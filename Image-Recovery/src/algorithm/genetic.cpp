#include "genetic.h"

Genetic::Genetic() = default;

void Genetic::checkProgress(int &generationId) {
    std::cout << "Generation: " << generationId << std::endl;
    if (((generationId % DataManager::getInstance()->getUserNGenerations()) == 0) || frameCompleted) {
        createImage();
    }
    createXML();
}

void Genetic::saveImage(QImage &image) const {
    DataManager::getInstance()->setCurrentFileGeneration(DataManager::getInstance()->getCurrentFileGeneration() + 1);
    QString path = DataManager::getInstance()->getFilesPath() + "solutions/" + QString(QString::fromStdString(std::to_string(DataManager::getInstance()->getCurrentFileGeneration()))) + ".png";
    bool saved = image.save(path);
    if (!saved) {
        qDebug() << "ERROR: The solution " << DataManager::getInstance()->getCurrentFileGeneration() << " was not successfully saved.";
        if (DataManager::getInstance()->getCurrentFileGeneration() != 0) {
            DataManager::getInstance()->setCurrentFileGeneration(DataManager::getInstance()->getCurrentFileGeneration() - 1);
        }
    }
    if (frameCompleted) {
        DataManager::getInstance()->setLastGenerationFile(DataManager::getInstance()->getCurrentFileGeneration());
    }
}

void Genetic::createImage() {
    QRgb color;
    int colorIndex = 0;
    QVector<QRgb> generationFrame = population.chromosomeList[population.fitChromosome].frame;
    QImage generationImage(DataManager::getInstance()->getImagePath());
    QDir genDir(DataManager::getInstance()->getFilesPath() + "solutions/");
    for (int y = DataManager::getInstance()->getFrameTopLeftPoint().y(); y < DataManager::getInstance()->getFrameBottomRightPoint().y(); ++y) {
        for (int x = DataManager::getInstance()->getFrameTopLeftPoint().x(); x < DataManager::getInstance()->getFrameBottomRightPoint().x(); ++x) {
            color = generationFrame.value(colorIndex++);
            generationImage.setPixel(x, y, color);
        }
    }
    if (genDir.exists()) {
        saveImage(generationImage);
    } else {
        qDebug() << "ERROR: The solution " << DataManager::getInstance()->getCurrentFileGeneration() + 1 << " was not successfully created.";
        genDir.mkpath("..///solutions/");
    }
}

void Genetic::saveXML(QFile &file) {
    file.open(QIODevice::WriteOnly);
    if (file.exists()) {
        QXmlStreamWriter xmlWriter(&file);
        xmlWriter.setAutoFormatting(true);
        xmlWriter.writeStartDocument();
            xmlWriter.writeStartElement("Generation");
                xmlWriter.writeTextElement("ID", QString(QString::fromStdString(std::to_string(generationID))));
                xmlWriter.writeTextElement("Fitness_Score", QString(QString::fromStdString(std::to_string(population.chromosomeList[population.fitChromosome].fitness))));
                xmlWriter.writeTextElement("Best_Chromosome", "Chromosome_" + QString(QString::fromStdString(std::to_string(population.fitChromosome))));
                xmlWriter.writeStartElement("Population");
                    for (int id = 0; id < 10; ++id) {
                        QString frame = "(";
                        xmlWriter.writeStartElement("Chromosome");
                        xmlWriter.writeAttribute("ID", QString(QString::fromStdString(std::to_string(id))));
                        xmlWriter.writeAttribute("Fitness_Score",QString(QString::fromStdString(std::to_string(population.chromosomeList[id].fitness))));
                        for (int gen = 0; gen < population.chromosomeList[id].frame.size(); ++gen) {
                            if (gen < population.chromosomeList[id].frame.size() - 1) {
                                frame = frame + QString(QString::fromStdString(std::to_string(population.chromosomeList[id].frame[gen]))) + ",";
                            } else {
                                frame = frame + QString(QString::fromStdString(std::to_string(population.chromosomeList[id].frame[gen])));
                            }
                        }
                        xmlWriter.writeTextElement("Solution", frame + ")");
                        xmlWriter.writeEndElement();
                    }
                xmlWriter.writeEndElement();
            xmlWriter.writeEndElement();
        xmlWriter.writeEndDocument();
        file.close();
    } else {
        qDebug() << "ERROR: The xml of generation " << QString(QString::fromStdString(std::to_string(generationID))) << " was not successfully saved.";
    }
}

void Genetic::createXML() {
    QDir genDir(DataManager::getInstance()->getFilesPath() + "information/");
    if (genDir.exists()) {
        QString path = DataManager::getInstance()->getFilesPath() + "information/Generation-" + QString(QString::fromStdString(std::to_string(generationID))) + ".xml";
        QFile generationFile(path);
        saveXML(generationFile);
    } else {
        qDebug() << "ERROR: The xml of generation " << QString(QString::fromStdString(std::to_string(generationID))) << " was not successfully created.";
        genDir.mkpath("..///information/");
    }
}

void Genetic::accuracyMeter(Chromosome &chromosome) {
    QVector<QRgb> reference = DataManager::getInstance()->getReference(); /**< Reference of image missing frame. */
    int sharedGenes = 0; /**< Number of pixels shared by the solution and the reference frame. */
    // comparison process (chromosome vs reference)
    for (int g = 0; g < reference.size(); ++g) {
        if (chromosome.frame[g] == reference[g]) {
            sharedGenes++;
        }
    }
    // chromosome fitness calculation
    chromosome.fitness = round((sharedGenes * 100) / reference.size());
    // check algorithm success condition
    if (chromosome.fitness == 100) {
        frameCompleted = true;
    }
}

void Genetic::mutationDetector(Chromosome &chromosome) {
    QVector<QRgb> reference = DataManager::getInstance()->getReference();
    for (int g = 0; g < reference.size(); ++g) {
        if (chromosome.frame[g] != reference[g]) {
            chromosome.mutations.append(g);
        }
    }
}

void Genetic::geneticAlgorithm(QProgressBar *progressBar) {
    while (!frameCompleted) { // create generations
        generationID++; // increases the generationID counter to assign the current value to the current generation.
        DataManager::getInstance()->setGenerationsAmount(DataManager::getInstance()->getGenerationsAmount() + 1); // increases the generation amount at Data Manager class
        if (generationID == 1) { //first generation - random
            Population initialPopulation;
            for (int c = 0; c < 10; ++c) { // population of 10 chromosomes (ID: 0-9)
                QVector<QRgb> chromosomeFrame = DataManager::getInstance()->getReference(); /**< Chromosome frame. */
                for (int g = 0; g < chromosomeFrame.size(); ++g) {
                    int genSwap = rand() % chromosomeFrame.size();
                    chromosomeFrame.swapItemsAt(g, genSwap); // exchanges the QRgb at index position g with the QRgb at index position genSwap
                }
                Chromosome generationChromosome(c, chromosomeFrame); /**< Chromosome with ID c, randomly generated frame and a score fitness of 0 (default). */
                initialPopulation.chromosomeList.append(generationChromosome); // adds the new chromosome to population
            }
            population = initialPopulation;
        } else {
            selection(population);
            mutation(population);
        }
        fitness(population);
        checkProgress(generationID);
        // update app progress bar
        progress = population.chromosomeList[population.fitChromosome].fitness;
        if (progressBar->value() < progress) {
            progressBar->setValue(progress);
        }
    }
}

void Genetic::fitness(Population &generation) {
    int bestChromosome = 0;
    for (int i = 0; i < 10; ++i) {
        accuracyMeter(generation.chromosomeList[i]);
        if (generation.chromosomeList[bestChromosome].fitness < generation.chromosomeList[i].fitness) {
            bestChromosome = i;
        }
    }
    generation.fitChromosome = bestChromosome;
}

void Genetic::selection(Population &generation) {
    int parentA = generation.fitChromosome;
    int parentB = 0;
    if (parentA == 0) {
        parentB = 1;
    }
    for (int c = 0; c < 10; ++c) {
        if (parentA != c && generation.chromosomeList[parentB].fitness < generation.chromosomeList[c].fitness) {
            parentB = c;
        }
    }
    crossover(generation.chromosomeList[parentA], generation.chromosomeList[parentB]);
}

void Genetic::crossover(const Chromosome &parentA, const Chromosome &parentB) {
    int referenceSize = parentA.frame.size();
    int half = referenceSize / 2;
    int third = referenceSize / 3;
    int quarter = referenceSize / 4;
    int eighth = referenceSize / 8;
    Population crossPopulation;
    QVector<QRgb> childFrame;
    for (int i = 0; i < 10; ++i) {
        childFrame.clear();
        switch (i) {
            case 0:
                childFrame.append(parentA.frame.sliced(0, half));
                childFrame.append(parentB.frame.sliced(half));
                break;
            case 1:
                childFrame.append(parentB.frame.sliced(0, half));
                childFrame.append(parentA.frame.sliced(half));
                break;
            case 2:
                childFrame.append(parentA.frame.sliced(0, third));
                childFrame.append(parentB.frame.sliced(third));
                break;
            case 3:
                childFrame.append(parentB.frame.sliced(0, third));
                childFrame.append(parentA.frame.sliced(third));
                break;
            case 4:
                childFrame.append(parentA.frame.sliced(0, third * 2));
                childFrame.append(parentB.frame.sliced(third * 2));
                break;
            case 5:
                childFrame.append(parentB.frame.sliced(0, third * 2));
                childFrame.append(parentA.frame.sliced(third * 2));
                break;
            case 6:
                childFrame.append(parentA.frame.sliced(0, quarter));
                childFrame.append(parentB.frame.sliced(quarter, quarter));
                childFrame.append(parentA.frame.sliced(half, quarter));
                childFrame.append(parentB.frame.sliced(quarter * 3));
                break;
            case 7:
                childFrame.append(parentB.frame.sliced(0, quarter));
                childFrame.append(parentA.frame.sliced(quarter, quarter));
                childFrame.append(parentB.frame.sliced(half, quarter));
                childFrame.append(parentA.frame.sliced(quarter * 3));
                break;
            case 8:
                childFrame.append(parentA.frame.sliced(0, eighth));
                childFrame.append(parentB.frame.sliced(eighth, eighth));
                childFrame.append(parentA.frame.sliced(quarter, eighth));
                childFrame.append(parentB.frame.sliced(eighth * 3, eighth));
                childFrame.append(parentA.frame.sliced(half, eighth));
                childFrame.append(parentB.frame.sliced(eighth * 5, eighth));
                childFrame.append(parentA.frame.sliced(quarter * 3, eighth));
                childFrame.append(parentB.frame.sliced(eighth * 7));
                break;
            case 9:
                childFrame.append(parentB.frame.sliced(0, eighth));
                childFrame.append(parentA.frame.sliced(eighth, eighth));
                childFrame.append(parentB.frame.sliced(quarter, eighth));
                childFrame.append(parentA.frame.sliced(eighth * 3, eighth));
                childFrame.append(parentB.frame.sliced(half, eighth));
                childFrame.append(parentA.frame.sliced(eighth * 5, eighth));
                childFrame.append(parentB.frame.sliced(quarter * 3, eighth));
                childFrame.append(parentA.frame.sliced(eighth * 7));
                break;
            default:
                qDebug() << "ERROR: Child identifier out of range.";
        }
        Chromosome child(i, childFrame);
        crossPopulation.chromosomeList.append(child);
    }
    population = crossPopulation;
}

void Genetic::mutation(Population &generation) {
    QVector<QRgb> colorPalette = DataManager::getInstance()->getColorPaletteReference();
    QVector<QRgb> frameSelected;
    QVector<int> mutationsAmount;
    QList<int> gensMutated;
    for (int c = 0; c < generation.chromosomeList.size(); ++c) {
        mutationDetector(generation.chromosomeList[c]);
        frameSelected = generation.chromosomeList[c].frame;
        mutationsAmount = generation.chromosomeList[c].mutations;
        gensMutated.clear();
        for (int g = 0; g < mutationsAmount.size(); ++g) {
            int genSelected = mutationsAmount[g];
            int colorSelected = rand() % colorPalette.size();
            if (gensMutated.count(genSelected) == 0) {
                if (frameSelected[genSelected] != colorPalette[colorSelected]) {
                    frameSelected[genSelected] = colorPalette[colorSelected];
                    gensMutated.append(genSelected);
                } else {
                    --g;
                }
            } else {
                --g;
            }
            generation.chromosomeList[c].frame = frameSelected;
        }
    }
}