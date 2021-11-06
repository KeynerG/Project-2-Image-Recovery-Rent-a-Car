#include "genetic.h"

Genetic::Genetic() {}

void Genetic::checkProgress(int &generationID) {
    if (frameCompleted || (generationID % DataManager::getInstance()->getUserNGenerations()) == 0) {
        createImage();
    }
}

void Genetic::saveImage(QImage &image) {
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
        qDebug() << "Generation: " << generationID;
    }
    qDebug() << "Generations Amount: " << generationID;
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
        if (c == parentA) {
            continue;
        }
        if (generations.last().chromosomeList[c].fitness > generations.last().chromosomeList[parentB].fitness) {
            parentB = c;
        }
    }
    crossover(generations.last().chromosomeList[parentA], generations.last().chromosomeList[parentA]);
}

void Genetic::crossover(Chromosome parentA, Chromosome parentB) {
    Population population;
    QVector<QRgb> childFrame;
    for (int i = 0; i < 10; ++i) {
        childFrame.clear();
        Chromosome child(i, childFrame);
        switch (i) {
            case 0:
                childFrame = parentA.frame;
                break;
            case 1:
                childFrame = parentB.frame;
                break;
            case 2:
                childFrame = parentA.frame.sliced(0, half);
                childFrame.append(parentB.frame.sliced(half));
                break;
            case 3:
                childFrame.append(parentB.frame.sliced(0, half));
                childFrame.append(parentA.frame.sliced(half));
                break;
            case 4:
                childFrame.append(parentA.frame.sliced(0, oneQuarter));
                childFrame.append(parentB.frame.sliced(oneQuarter, oneQuarter));
                childFrame.append(parentA.frame.sliced(half, oneQuarter));
                childFrame.append(parentB.frame.sliced(oneQuarter * 3));
                break;
            case 5:
                childFrame.append(parentB.frame.sliced(0, oneQuarter));
                childFrame.append(parentA.frame.sliced(oneQuarter, oneQuarter));
                childFrame.append(parentB.frame.sliced(half, oneQuarter));
                childFrame.append(parentA.frame.sliced(oneQuarter * 3));
                break;
            case 6:
                childFrame.append(parentB.frame.sliced(0, oneQuarter));
                childFrame.append(parentA.frame.sliced(oneQuarter, half));
                childFrame.append(parentB.frame.sliced(oneQuarter * 3));
                break;
            case 7:
                childFrame.append(parentA.frame.sliced(0, oneQuarter));
                childFrame.append(parentB.frame.sliced(oneQuarter, half));
                childFrame.append(parentA.frame.sliced(oneQuarter * 3));
                break;
            case 8:
                childFrame.append(parentA.frame.sliced(0, oneEight));
                childFrame.append(parentB.frame.sliced(oneEight, oneEight));
                childFrame.append(parentA.frame.sliced(oneQuarter, oneEight));
                childFrame.append(parentB.frame.sliced(oneEight * 3, oneEight));
                childFrame.append(parentA.frame.sliced(half, oneEight));
                childFrame.append(parentB.frame.sliced(oneEight * 5, oneEight));
                childFrame.append(parentA.frame.sliced(oneQuarter * 3, oneEight));
                childFrame.append(parentB.frame.sliced(oneEight * 7));
                break;
            case 9:
                childFrame.append(parentB.frame.sliced(0, oneEight));
                childFrame.append(parentA.frame.sliced(oneEight, oneEight));
                childFrame.append(parentB.frame.sliced(oneQuarter, oneEight));
                childFrame.append(parentA.frame.sliced(oneEight * 3, oneEight));
                childFrame.append(parentB.frame.sliced(half, oneEight));
                childFrame.append(parentA.frame.sliced(oneEight * 5, oneEight));
                childFrame.append(parentB.frame.sliced(oneQuarter * 3, oneEight));
                childFrame.append(parentA.frame.sliced(oneEight * 7));
                break;
            default:
                qDebug() << "ERROR: Child identifier out of range.";
        }
        child.frame = childFrame;
        population.chromosomeList.append(child);
    }
    generation.append(population);
}

void Genetic::mutation(QList<Population> &generations) {
    int chromosomeRandom = rand() % 10;
    Chromosome chromosomeSelected = generations.last().chromosomeList[chromosomeRandom];
    QVector<QRgb> frameSelected = chromosomeSelected.frame;
    QVector<QRgb> colorPalette = DataManager::getInstance()->getColorPaletteReference();
    int mutationsAmount = rand() % frameSelected.size() / 2 + 1;
    QList<int> gensMutated;
    qDebug() << "Chromosome's frame: " << frameSelected;
    qDebug() << "Mutations Amount: " << mutationsAmount;
    for (int g = 0; g < mutationsAmount; ++g) {
        int genSelected = rand() % frameSelected.size();
        int colorSelected = rand() % colorPalette.size();
        if (gensMutated.count(genSelected) == 0) {
            qDebug() << "Gen " << genSelected << " - Value " << frameSelected[genSelected] << " || Color " << colorSelected << " - Value " << colorPalette[colorSelected];
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
    qDebug() << "Chromosome's new frame: " << frameSelected;
}