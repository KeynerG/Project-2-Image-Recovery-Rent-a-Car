#ifndef IMAGE_RECOVERY_GENETIC_H
#define IMAGE_RECOVERY_GENETIC_H

#include "src/algorithm/datamanager.h"

#include <iostream>
#include <QDebug>
#include <QImage>
#include <QList>
#include <QRgb>
#include <QVector>
#include <QProgressBar>

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
    QList<Population> generation; /**<  */
    int generationID = 0;  /**< Generation identifier counter. */
    bool frameCompleted = false; /**< Determines if the missing frame of the image has been completed successfully. */

    Genetic(); /**< Genetic class constructor. */

    /**
     * @fn void checkProgress(int &generationID)
     * @brief
     * @param generationId
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void checkProgress(int &generationId);

    /**
     * @fn void saveImage(QImage &image)
     * @brief
     * @param image
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void saveImage(QImage &image) const;

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
     * @param progresBar
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void geneticAlgorithm(QProgressBar *progressBar);

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
     * @param parentA
     * @param parentB
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     */
    void crossover(const Chromosome &parentA, const  Chromosome &parentB);

    /**
     * @fn void mutation(QList<Population> &generations)
     * @brief
     * @param generations
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     */
    void mutation(QList<Population> &generations) const;

    /**
     * @fn void inversion(QList<Population> &generations)
     * @brief
     * @param generations
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     */
    void inversion(QList<Population> &generations);
};

#endif //IMAGE_RECOVERY_GENETIC_H
