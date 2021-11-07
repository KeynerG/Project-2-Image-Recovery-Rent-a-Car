#include "genetic.h"

Genetic::Genetic() = default;

void Genetic::checkProgress(int &generationId) {
    qDebug() << "\nCheckProgress() - Generation " << generationId;
    if (frameCompleted || (generationId % DataManager::getInstance()->getUserNGenerations()) == 0) {
        createImage();
    }
}

void Genetic::saveImage(QImage &image) const {
    qDebug() << "\nSaveImage() - Generation " << generationID;
    DataManager::getInstance()->setCurrentFileGeneration(DataManager::getInstance()->getCurrentFileGeneration() + 1);
    QString path = DataManager::getInstance()->getFilesPath() + QString(QString::fromStdString(std::to_string(DataManager::getInstance()->getCurrentFileGeneration()))) + ".png";
    bool saved = image.save(path);
    if (!saved) {
        qDebug() << "ERROR: The image of generation " << DataManager::getInstance()->getCurrentFileGeneration() << " was not successfully saved.";
        if (DataManager::getInstance()->getCurrentFileGeneration() != 0) {
            DataManager::getInstance()->setCurrentFileGeneration(DataManager::getInstance()->getCurrentFileGeneration() - 1);
        }
    }
    if (frameCompleted) {
        DataManager::getInstance()->setLastGenerationFile(DataManager::getInstance()->getCurrentFileGeneration());
    }
}

void Genetic::createImage() {
    qDebug() << "\nCreateImage() - Generation " << generationID;
    QRgb color;
    int colorIndex = 0;
    qDebug() << "Fit Chromosome ID: " << generation.last().fitChromosome;
    qDebug() << "Fit Chromosome frame: " << generation.last().chromosomeList[generation.last().fitChromosome].frame;
    QVector<QRgb> generationFrame = generation.last().chromosomeList[generation.last().fitChromosome].frame;
    QImage generationImage(DataManager::getInstance()->getImagePath());
    for (int y = DataManager::getInstance()->getFrameTopLeftPoint().y(); y < DataManager::getInstance()->getFrameBottomRightPoint().y(); ++y) {
        for (int x = DataManager::getInstance()->getFrameTopLeftPoint().x(); x < DataManager::getInstance()->getFrameBottomRightPoint().x(); ++x) {
            color = generationFrame.value(colorIndex++);
            generationImage.setPixel(x, y, color);
        }
    }
    saveImage(generationImage);
}

void Genetic::accuracyMeter(Chromosome &chromosome) {
    qDebug() << "AccuracyMeter() - Generation " << generationID;
    QVector<QRgb> reference = DataManager::getInstance()->getReference(); /**< Reference of image missing frame. */
    int sharedGenes = 0; /**< Number of pixels shared by the solution and the reference frame. */
    for (int g = 0; g < reference.size(); ++g) {
        if (chromosome.frame[g] == reference[g]) {
            sharedGenes++;
        }
    }
    chromosome.fitness = round((sharedGenes * 100) / reference.size());
    if (chromosome.fitness == 100) {
        frameCompleted = true;
    }
}

void Genetic::createXML() {

}

void Genetic::geneticAlgorithm() {
//    while (!frameCompleted) { // create generations
    while (generationID < 5) {
        generationID++; // increases the generationID counter to assign the current value to the current generation.
        DataManager::getInstance()->setGenerationsAmount(DataManager::getInstance()->getGenerationsAmount() + 1); // increases the generation amount at Data Manager class
        qDebug() << "\n ----------- GeneticAlgorithm() - Generation " << generationID << " -----------\n";
        if (generationID == 1) { //first generation - random
            Population initialPopulation;
            for (int c = 0; c < 10; ++c) { // population of 10 chromosomes (ID: 0-9)
                QVector<QRgb> chromosomeFrame = DataManager::getInstance()->getReference(); /**< Chromosome frame. */
                for (int g = 0; g < chromosomeFrame.size(); ++g) {
                    int genSwap = rand() % chromosomeFrame.size();
                    chromosomeFrame.swapItemsAt(g, genSwap); // exchanges the QRgb at index position g with the QRgb at index position genSwap
                }
                Chromosome generationChromosome(c, chromosomeFrame); /**< Chromosome with ID c, randomly generated frame and a score fitness of 0 (default). */
                qDebug() << "Chromosome: " << c << "Frame: " << chromosomeFrame;
                initialPopulation.chromosomeList.append(generationChromosome); // adds the new chromosome to population
                qDebug() << "Population size: " << initialPopulation.chromosomeList.size(); // chromosomes amount
            }
            generation.append(initialPopulation);
        } else {
            selection(generation); //Selection and crossover, selection calls the crossover function
            mutation(generation);
        }
        fitness(generation);
        checkProgress(generationID);
    }
    qDebug() << "Generations Amount: " << generationID;
}

void Genetic::fitness(QList<Population> &generations) {
    qDebug() << "\nFitness() - Generation " << generationID;
    int bestChromosome = 0;
    for (int i = 0; i < 10; ++i) {
        accuracyMeter(generations.last().chromosomeList[i]);
        if (generations.last().chromosomeList[i].fitness > generations.last().chromosomeList[bestChromosome].fitness) {
            bestChromosome = i;
        }
    }
    qDebug() << "Best Chromosome - ID: " << bestChromosome << " - Fitness Score: " << generations.last().chromosomeList[bestChromosome].fitness;
    generations.last().fitChromosome = bestChromosome;
}

void Genetic::selection(QList<Population> &generations) { //Select the two Chromosomes with the best fitness
    qDebug() << "\nSelection() - Generation " << generationID;
    int parentA = generations.last().fitChromosome;
    int parentB = 0;
    if (parentA == 0) {
        parentB = 1;
    }
    for (int c = 0; c < 10; ++c) {
        qDebug() << "Parent X - ID: " << c << " - Fitness Score: " << generations.last().chromosomeList[c].fitness;
        if (parentA != c && generations.last().chromosomeList[c].fitness > generations.last().chromosomeList[parentB].fitness) {
            parentB = c;
        }
    }
    qDebug() << "Results:\nParent A - ID: " << parentA << " - Frame: " << generations.last().chromosomeList[parentA].frame;
    qDebug() << "Parent B - ID: " << parentB << " - Frame: " << generations.last().chromosomeList[parentB].frame;
    crossover(generations.last().chromosomeList[parentA], generations.last().chromosomeList[parentB]);
}

void Genetic::crossover(const Chromosome &parentA, const Chromosome &parentB) {
    int referenceSize = parentA.frame.size();
    int half = referenceSize / 2;
    int third = referenceSize / 3;
    int quarter = referenceSize / 4;
    int eighth = referenceSize / 8;
    qDebug() << "\nCrossover() - Generation " << generationID;
    Population population;
    QVector<QRgb> childFrame;
    // creation process (crossover)
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
                childFrame.append(parentA.frame.sliced(third));
                childFrame.append(parentB.frame.sliced(0, third));
                break;
            case 5:
                childFrame.append(parentB.frame.sliced(third));
                childFrame.append(parentA.frame.sliced(0, third));
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
        // verification process - the child frame cannot be equal to either parent
        if (childFrame == parentA.frame || childFrame == parentB.frame) {
            for (int g = 0; g < childFrame.size() / 2; ++g) {
                int genSwap = rand() % childFrame.size();
                childFrame.swapItemsAt(g, genSwap); // exchanges the QRgb at index position g with the QRgb at index position genSwap
            }
        }
        // setting process
        Chromosome child(i, childFrame);
        qDebug() << "Child " << i << child.frame;
        // addition process
        population.chromosomeList.append(child);
    }
    generation.append(population);
}

void Genetic::mutation(QList<Population> &generations) const {
    qDebug() << "\nMutation() - Generation " << generationID;
    int chromosomeRandom = rand() % 10;
    QVector<QRgb> frameSelected = generations.last().chromosomeList[chromosomeRandom].frame;
    QVector<QRgb> colorPalette = DataManager::getInstance()->getColorPaletteReference();
    int mutationsAmount = rand() % frameSelected.size() / colorPalette.size() + 1;
    QList<int> gensMutated;
    qDebug() << "Chromosome selected - ID: " << chromosomeRandom;
    qDebug() << "Frame: " << frameSelected;
    qDebug() << "Mutations Amount: " << mutationsAmount;
    for (int g = 0; g < mutationsAmount; ++g) {
        int genSelected = rand() % frameSelected.size();
        int colorSelected = rand() % colorPalette.size();
        if (gensMutated.count(genSelected) == 0) {
            if (frameSelected[genSelected] != colorPalette[colorSelected]) {
                frameSelected[genSelected] = colorPalette[colorSelected];
                gensMutated.append(genSelected);
                qDebug() << "Mutation: Gen " << genSelected << " - Color " << frameSelected[genSelected];
            } else {
                --g;
            }
        } else {
            --g;
        }
    }
    generations.last().chromosomeList[chromosomeRandom].frame = frameSelected;
    qDebug() << "Result frame: " << generations.last().chromosomeList[chromosomeRandom].frame;
}