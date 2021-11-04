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
    Population(int populationID, QList<Chromosome> &chromosomeFrame, int chromosomeIndex) {
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
    Population population; /**< List of possible frames as solutions to the missing frame. */
    int generationID = 0;  /**< Generation identifier counter. */
    bool frameCompleted; /**< Determines if the missing frame of the image has been completed successfully. */

public:

    /**
     * @fn bool checkGenerationNumber()
     * @brief
     * @param generationID
     * @return boolean
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    bool checkGenerationNumber(int &generationID);

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
     * @fn void fitness()
     * @brief
     * @param gens
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     */
    void fitness(QList<Population> gens);

    /**
     * @fn void selection()
     * @brief
     * @param generations
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     */
    void selection(QList<Population> &generations);

    /**
     * @fn void crossover()
     * @brief
     * @param parent1
     * @param parent2
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     */
    void crossover(Chromosome parent1, Chromosome parent2);

    /**
     * @fn void mutation()
     * @brief
     * @param generations
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     */
    void mutation(QList<Population> &generations);

    /**
     * @fn void createXML()
     * @brief
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     */
    void createXML();

    /**
     * @fn void createImage()
     * @brief
     * @param generationNumber
     * @param image
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void createImage(int &generationNumber, QImage &image);
};

#endif //IMAGE_RECOVERY_GENETIC_H