#ifndef IMAGE_RECOVERY_GENETIC_H
#define IMAGE_RECOVERY_GENETIC_H

#include "src/algorithm/datamanager.h"

#include <QDebug>
#include <QImage>
#include <QList>
#include <QRgb>
#include <QVector>

using namespace std;

/**
 * @struct Chromosome
 * @brief
 * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
 */
struct Chromosome {
    Chromosome(int chromosomeID, QVector<QRgb> &chromosomeFrame, int chromosomeFitnessScore = 0) {
        ID = chromosomeID;
        frame = chromosomeFrame;
        fitness = chromosomeFitnessScore;
    }

    int ID; /**< Chromosome identifier. */
    QVector<QRgb> frame; /**< Solution to the missing frame. */
    int fitness; /**< Similarity score respect to the reference image. */
};

/**
 * @struct Population
 * @brief
 * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
 */
struct Population {
    Population() {
        ID = 0;
        chromosomeList = QList<Chromosome>();
        fitChromosome = 0;
    }

    Population(int populationID, QList<Chromosome> &chromosomeFrame, int chromosomeIndex = 0) {
        ID = populationID;
        chromosomeList = chromosomeFrame;
        fitChromosome = chromosomeIndex;
    }

    int ID; /**< Population identifier. */
    QList<Chromosome> chromosomeList; /**< Chromosomes list in the current population. */
    int fitChromosome; /**< Index of the Chromosome with the best fitness. */
};

/**
 * @class Genetic
 * @brief
 * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
 */
class Genetic {

private:
    QList<Population> generation; /**<  */
    int generationID = 0;  /**< Generation identifier counter. */
    int referenceSize = DataManager::getInstance()->getReference().size();
    int half = referenceSize / 2;
    int oneQuarter = referenceSize / 4;
    int oneEight = referenceSize / 8;
    bool frameCompleted; /**< Determines if the missing frame of the image has been completed successfully. */

public:

    Genetic();

    /**
     * @fn bool checkProgress(int &generationID)
     * @brief
     * @param generationID
     * @return boolean
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    bool checkProgress(int &generationID);

    /**
     * @fn void saveImage(QImage &image)
     * @brief
     * @param image
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void saveImage(QImage &image);

    /**
     * @fn void createImage()
     * @brief
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void createImage();

    /**
     * @fn void createXML()
     * @brief
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     */
    void createXML();

    /**
     * @fn void accuracyMeter(Chromosome &chromosome)
     * @brief
     * @param chromosome
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void accuracyMeter(Chromosome &chromosome);

    /**
     * @fn void geneticAlgorithm()
     * @brief
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void geneticAlgorithm();

    /**
     * @fn void fitness(QList<Population> &generations)
     * @brief
     * @param generations
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     */
    void fitness(QList<Population> &generations);

    /**
     * @fn void selection(QList<Population> &generations)
     * @brief
     * @param generations
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     */
    void selection(QList<Population> &generations);

    /**
     * @fn void crossover(Chromosome parentA, Chromosome parentB)
     * @brief
     * @param parent1
     * @param parent2
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     */
    void crossover(Chromosome parentA, Chromosome parentB);

    /**
     * @fn void mutation(QList<Population> &generations)
     * @brief
     * @param generations
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     */
    void mutation(QList<Population> &generations);
};

#endif //IMAGE_RECOVERY_GENETIC_H