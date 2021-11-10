#ifndef IMAGE_RECOVERY_GENETIC_H
#define IMAGE_RECOVERY_GENETIC_H

#include "src/algorithm/datamanager.h"

#include <iostream>
#include <QDebug>
#include <QDir>
#include <QImage>
#include <QList>
#include <QProgressBar>
#include <QRgb>
#include <QVector>
#include <QXmlStreamWriter>

using namespace std;

/**
 * @struct Chromosome
 * @brief This struct is created like an Object that have the variables of chromosomeFrame, mutations, ID and fitness.
 * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
 */
struct Chromosome {
    Chromosome(int chromosomeID, QVector<QRgb> &chromosomeFrame, int chromosomeFitnessScore = 0) {
        ID = chromosomeID;
        frame = chromosomeFrame;
        fitness = chromosomeFitnessScore;
        mutations = QList<int>();
    }

    int ID; /**< Chromosome identifier. */
    QVector<QRgb> frame; /**< Solution to the missing frame. */
    int fitness; /**< Similarity score respect to the reference image. */
    QList<int> mutations; /**< Number of pixels different (QRgb) from the reference image. */
};

/**
 * @struct Population
 * @brief This struct is created like an Object that have the variables of chromosomeList, ID and fitChromosome.
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
 * @brief This class have all the logic for the genetic algorithm.
 * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
 * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
 */
class Genetic {

public:
    Population population; /**< Reference to Population structure. */
    int generationID = 0;  /**< Generation identifier counter. */
    bool frameCompleted = false; /**< Determines if the missing frame of the image has been completed successfully. */
    int progress; /**< Progress reference. */

    Genetic(); /**< Genetic class constructor. */

    /**
     * @fn void checkProgress(int &generationId)
     * @brief This method receives the generationId and evaluates if that generation have to be saved in an image calling createImage().
     * @param generationId
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void checkProgress(int &generationId);

    /**
     * @fn void saveImage(QImage &image) const
     * @brief This method receives the image generated in createImage() and saves it with an unique name.
     * @param image
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void saveImage(QImage &image) const;

    /**
     * @fn void createImage()
     * @brief This method takes the fitChromosome of the current generation and makes a QImage, then send it to saveImage().
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void createImage();

    /**
     * @fn void saveXML(QFile &file)
     * @brief This method receives the generated XML in createXML() and saves it with an unique name.
     * @param file
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void saveXML(QFile &file);

    /**
     * @fn void createXML()
     * @brief This method takes the information of the current generation and write a XML whit the information.
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void createXML();

    /**
     * @fn void accuracyMeter(Chromosome &chromosome)
     * @brief This method receives a Chromosome a detects how many pixels are equals to the pixels in the reference.
     * @param chromosome
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void accuracyMeter(Chromosome &chromosome);

    /**
     * @fn void mutationDetector(Chromosome &chromosome)
     * @brief This method receives a Chromosome a detects which pixels are not equals to the pixels in the reference.
     * @param chromosome
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void mutationDetector(Chromosome &chromosome);

    /**
     * @fn void geneticAlgorithm(QProgressBar *progressBar)
     * @brief This method is the main loop of the genetic, it generates the first generation randomly and call the other functions to make new generations until find the perfect chromosome.
     * @param progressBar
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void geneticAlgorithm(QProgressBar *progressBar);

    /**
     * @fn void fitness(Population &generation)
     * @brief This method receives the current generation and send each Chromosome to the function accuracyMeter(), then it saves the Chromosome with the highest fitness in the fitChromosome variable.
     * @param generation
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     */
    void fitness(Population &generation);

    /**
     * @fn void selection(Population &generation)
     * @brief This method receives the current generation and select the two chromosomes with the highest fitness.
     * @param generation
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     */
    void selection(Population &generation);

    /**
     * @fn void crossover(const Chromosome &parentA, const Chromosome &parentB)
     * @brief This method receives two chromosomes and make 10 new chromosomes mixing them.
     * @param parentA
     * @param parentB
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void crossover(const Chromosome &parentA, const Chromosome &parentB);

    /**
     * @fn void mutation(Population &generation)
     * @brief This method receives the current generation, select a random chromosome and change values of the frame to makes mutations.
     * @param generation
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void mutation(Population &generation);
};

#endif //IMAGE_RECOVERY_GENETIC_H