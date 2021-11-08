#ifndef IMAGE_RECOVERY_GENETIC_H
#define IMAGE_RECOVERY_GENETIC_H

#include "src/algorithm/datamanager.h"

#include <iostream>
#include <QDebug>
#include <QImage>
#include <QList>
#include <QProgressBar>
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
    int fitChromosome; /**< Index of the Chromosome with the best fitness score. */
};

/**
 * @class Genetic
 * @brief
 * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
 * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
 */
class Genetic {

public:
    Population population; /**<  */
    int generationID = 0;  /**< Generation identifier counter. */
    bool frameCompleted = false; /**< Determines if the missing frame of the image has been completed successfully. */
    int progress; /**< Progress reference. */

    Genetic(); /**< Genetic class constructor. */

    /**
     * @fn checkProgress
     * @brief
     * @param generationId
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void checkProgress(int &generationId);

    /**
     * @fn saveImage
     * @brief
     * @param image
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void saveImage(QImage &image) const;

    /**
     * @fn createImage
     * @brief
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void createImage();

    /**
     * @fn createXML
     * @brief
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     */
    void createXML();

    /**
     * @fn accuracyMeter
     * @brief
     * @param chromosome
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void accuracyMeter(Chromosome &chromosome);

    /**
     * @fn geneticAlgorithm
     * @brief
     * @param progressBar
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void geneticAlgorithm(QProgressBar *progressBar);

    /**
     * @fn fitness
     * @brief
     * @param generation
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     */
    void fitness(Population &generation);

    /**
     * @fn selection
     * @brief
     * @param generation
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     */
    void selection(Population &generation);

    /**
     * @fn crossover
     * @brief
     * @param parentA
     * @param parentB
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void crossover(const Chromosome &parentA, const Chromosome &parentB);

    /**
     * @fn mutation
     * @brief
     * @param generation
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    static void mutation(Population &generation) ;

    /**
     * @fn inversion
     * @brief
     * @param generation
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    static void inversion(Population &generation);
};

#endif //IMAGE_RECOVERY_GENETIC_H