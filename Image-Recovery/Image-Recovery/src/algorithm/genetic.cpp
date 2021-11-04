#include "genetic.h"

bool Genetic::checkGenerationNumber(int &generationID) {
    if ((generationID % DataManager::getInstance()->getUserNGenerations()) == 0 || generationID == DataManager::getInstance()->getLastGenerationFile()) {
        return true;
    } else {
        return false;
    }
}

void Genetic::accuracyMeter(Chromosome &chromosome) {
    QVector<QRgb> reference = DataManager::getInstance()->getReference(); /**< Reference of image missing frame. */
    int sharedGenes = 0; /**< Number of pixels shared by the solution and the reference frame. */
    if (chromosome.frame == reference) {
        frameCompleted = true;
        chromosome.fitness = 100;
    } else {
        frameCompleted = false;
        for (int g = 0; g < reference.size(); ++g) {
            if (chromosome.frame[g] == reference[g]) {
                sharedGenes++;
            }
        }
        chromosome.fitness = round((sharedGenes * 100) / reference.size());
    }
}

void Genetic::geneticAlgorithm() {
    while (!frameCompleted) { // create generations
        generationID++; // increases the generationID counter to assign the current value to the current generation.
        if (generationID == 1) { //first generation - random
            Population initialPopulation;
            for (int c = 0; c < 10; ++c) { // population of 10 chromosomes (ID: 0-9)
                QVector<QRgb> chromosomeFrame; /**< Chromosome frame. */
                for (int g = 0; g < referenceSize; ++g) {
                    int genSwap = rand() % referenceSize;
                    chromosomeFrame.swapItemsAt(g, genSwap); // exchanges the QRgb at index position g with the QRgb at index position genSwap
                }
                Chromosome generationChromosome(c, chromosomeFrame); /**< Chromosome with ID c, randomly generated frame and a score fitness of 0 (default). */
                qDebug() << "Chromosome: " << c << "\n" << "Frame: " << chromosomeFrame;
                initialPopulation.chromosomeList.append(generationChromosome); // adds the new chromosome to population
                qDebug() << "Population: " << initialPopulation.chromosomeList.size(); // chromosomes amount
            }
            generation.append(initialPopulation);
            qDebug() << "Generation size: " << generation.size();
        } else {
            selection(generation); //Selection and crossover, selection calls the crossover function
        }
    }
}

void Genetic::fitness(QList<Population> &generations) {

}

void Genetic::selection(QList<Population> &generations) { //Select the two Chromosomes with the best fitness
    int parentA = generations.last().fitChromosome;
    int parentB;
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
        }
        child.frame = childFrame;
        population.chromosomeList.append(child);
    }
    generation.append(population);
}

void Genetic::mutation(QList<Population> &generations) {

}

void Genetic::createXML() {

}

void Genetic::createImage(int &generationNumber, QImage &image) {
    bool saveStatement = checkGenerationNumber(generationNumber);
    if (saveStatement) {
        DataManager::getInstance()->setCurrentFileGeneration(DataManager::getInstance()->getCurrentFileGeneration() + 1);
        QString path = DataManager::getInstance()->getFilesPath() + QString(QString::fromStdString(std::to_string(DataManager::getInstance()->getCurrentFileGeneration()))) + ".png";
        bool saved = image.save(path);
        if (!saved) {
            qDebug() << "ERROR: The image of generation " << DataManager::getInstance()->getCurrentFileGeneration() << " was not successfully saved.";
            if (DataManager::getInstance()->getCurrentFileGeneration() != 0) {
                DataManager::getInstance()->setCurrentFileGeneration(DataManager::getInstance()->getCurrentFileGeneration() - 1);
            }
        }
    }
}