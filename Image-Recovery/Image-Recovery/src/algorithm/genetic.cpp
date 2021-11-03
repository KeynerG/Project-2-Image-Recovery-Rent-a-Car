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
        generationID++; // Increases the generationID counter to assign the current value to the current generation.
        if (generationID == 1) { //first generation - random
            //int allelesAmount = DataManager::getInstance()->getColorTableReference().size(); /**< It's the number of colors that the reference of the missing part contains. */
            int genesAmount = DataManager::getInstance()->getReference().size(); /**< Image pixels amount. */
            for (int i = 0; i < 10; i++) { //10 chromosome per population
                QVector<QRgb> tmpFrame = DataManager::getInstance()->getReference(); /**< Chromosome temporary frame. */
                QVector<QRgb> chromosomeFrame; /**< Chromosome official frame. */
                for (int g = 0; g < genesAmount; g++) {
                    int remainingGenes = tmpFrame.size(); /**< Remaining image pixels. */
                    int currentGen = rand() % (remainingGenes); /**< Current image pixel. */
                    chromosomeFrame.push_back(tmpFrame[currentGen]);
                    tmpFrame.removeAt(currentGen);
                }
                Chromosome generationChromosome(i, chromosomeFrame); /**< Chromosome with ID i, randomly generated frame and a score fitness of 0 (default). */
                qDebug() << "Chromosome: " << i << "\n" << "Frame: " << chromosomeFrame;
                population.append(generationChromosome);
                qDebug() << "Chromosomes Amount: " << population.size();
            }
            generation.addNodeAtEnd(population);
        } else {
            // case --> 1 < generationID
        }
    }
}

void Genetic::fitness(SimpleList<SimpleList<Chromosome>> gens) {

}

void Genetic::selection() {

}

void Genetic::crossover() {

}

void Genetic::mutation() {

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