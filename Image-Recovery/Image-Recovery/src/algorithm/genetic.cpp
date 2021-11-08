#include "genetic.h"

Genetic::Genetic() = default;

void Genetic::checkProgress(int &generationId) {
    if (frameCompleted || (generationId % DataManager::getInstance()->getUserNGenerations()) == 0) {
        createImage();
    }
}

void Genetic::saveImage(QImage &image) const {
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
    QRgb color;
    int colorIndex = 0;
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
            generation.append(initialPopulation);
        } else {
            selection(generation); //Selection and crossover, selection calls the crossover function
            mutation(generation);
            inversion(generation);
        }
        fitness(generation);
        checkProgress(generationID);
        std::cout << "Generation: " << generationID << std::endl;
    }
}

void Genetic::fitness(QList<Population> &generations) {
    int bestChromosome = 0;
    for (int i = 0; i < 10; ++i) {
        accuracyMeter(generations.last().chromosomeList[i]);
        if (generations.last().chromosomeList[i].fitness > generations.last().chromosomeList[bestChromosome].fitness) {
            bestChromosome = i;
        }
    }
    generations.last().fitChromosome = bestChromosome;
}

void Genetic::selection(QList<Population> &generations) { //Select the two Chromosomes with the best fitness
    int parentA = generations.last().fitChromosome;
    int parentB = 0;
    if (parentA == 0) {
        parentB = 1;
    }
    for (int c = 0; c < 10; ++c) {
        if (parentA != c && generations.last().chromosomeList[c].fitness > generations.last().chromosomeList[parentB].fitness) {
            parentB = c;
        }
    }
    crossover(generations.last().chromosomeList[parentA], generations.last().chromosomeList[parentB]);
}

void Genetic::crossover(const Chromosome &parentA, const Chromosome &parentB) {
    int referenceSize = parentA.frame.size();
    int half = referenceSize / 2;
    int third = referenceSize / 3;
    int quarter = referenceSize / 4;
    int eighth = referenceSize / 8;
    Population population;
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
        Chromosome child(i, childFrame);
        population.chromosomeList.append(child);
    }
    generation.append(population);
}

void Genetic::mutation(QList<Population> &generations) const {
    int chromosomeRandom = rand() % 10;
    QVector<QRgb> frameSelected = generations.last().chromosomeList[chromosomeRandom].frame;
    QVector<QRgb> colorPalette = DataManager::getInstance()->getColorPaletteReference();
    int mutationsAmount = rand() % frameSelected.size() / colorPalette.size() + 1;
    QList<int> gensMutated;
    for (int g = 0; g < mutationsAmount; ++g) {
        int genSelected = rand() % frameSelected.size();
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
    }
    generations.last().chromosomeList[chromosomeRandom].frame = frameSelected;
}

void Genetic::inversion(QList<Population> &generations){
    int chromosomeRandom = rand() % 10;
    QVector<QRgb> tmpFrame = generations.last().chromosomeList[chromosomeRandom].frame;
    QVector<QRgb> InvertedFrame;
    for (int i = 0; i < generations.last().chromosomeList[chromosomeRandom].frame.size(); ++i) {
        InvertedFrame.append(tmpFrame.last());
        tmpFrame.removeLast();
    }
    generations.last().chromosomeList[chromosomeRandom].frame = InvertedFrame;
}