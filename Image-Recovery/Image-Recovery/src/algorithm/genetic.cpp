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
            int genesAmount = DataManager::getInstance()->getReference().size(); /**< Image pixels amount. */
            for (int c = 0; c < 10; ++c) { // population of 10 chromosomes (ID: 0-9)
                QVector<QRgb> chromosomeFrame; /**< Chromosome frame. */
                for (int g = 0; g < genesAmount; ++g) {
                    int genSwap = rand() % genesAmount;
                    chromosomeFrame.swapItemsAt(g, genSwap); // exchanges the QRgb at index position g with the QRgb at index position genSwap
                }
                Chromosome generationChromosome(c, chromosomeFrame); /**< Chromosome with ID c, randomly generated frame and a score fitness of 0 (default). */
                qDebug() << "Chromosome: " << c << "\n" << "Frame: " << chromosomeFrame;
                population.chromosomeList.append(generationChromosome); // adds the new chromosome to population
                qDebug() << "Population: " << population.chromosomeList.size(); // chromosomes amount
            }
            generation.append(population);
        } else {
            selection(generation); //Selection and crossover, selection calls the crossover function
        }
    }
}

void Genetic::fitness(QList<Population> gens) {

}

void Genetic::selection(QList<Population> &generations) { //Select the two Chromosomes with the best fitness
    int parent1 = generations.last().fitChromosome;
    int parent2;
    if (parent1 == 0) {
        parent2 = 1;
    }
    for (int c = 0; c < 10; ++c) {
        if (c == parent1) {
            continue;
        }
        if (generations.last().chromosomeList[c].fitness > generations.last().chromosomeList[parent2].fitness) {
            parent2 = c;
        }
    }
    crossover(generations.last().chromosomeList[parent1], generations.last().chromosomeList[parent1]);
}

void Genetic::crossover(Chromosome parent1, Chromosome parent2) {
    for (int c = 0; c < 10; ++c) { // population of 10 chromosomes (ID: 0-9)
        QVector<QRgb> chromosomeFrame; /**< Chromosome frame. */
        //crossover method
        Chromosome generationChromosome(c, chromosomeFrame);
        qDebug() << "Chromosome: " << c << "\n" << "Frame: " << chromosomeFrame;
        population.chromosomeList.append(generationChromosome); // adds the new chromosome to population
    }
}

void Genetic::mutation(QList<Population> &generations) {

}

void Genetic::createXML() {

}

void Genetic::createImage(int &generationNumber, QImage &image) {
    bool saveStatement = checkGenerationNumber(generationNumber);
    if (saveStatement) {
        DataManager::getInstance()->setCurrentFileGeneration(DataManager::getInstance()->getCurrentFileGeneration() + 1);
        QString path = "../src/generations/" + QString(QString::fromStdString(std::to_string(DataManager::getInstance()->getCurrentFileGeneration()))) + ".png";
        bool saved = image.save(path);
        if (!saved) {
            qDebug() << "ERROR: The image of generation " << DataManager::getInstance()->getCurrentFileGeneration() << " was not successfully saved.";
            if (DataManager::getInstance()->getCurrentFileGeneration() != 0) {
                DataManager::getInstance()->setCurrentFileGeneration(DataManager::getInstance()->getCurrentFileGeneration() - 1);
            }
        }
    }
}