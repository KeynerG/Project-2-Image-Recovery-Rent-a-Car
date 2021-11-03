#ifndef IMAGE_RECOVERY_GENETIC_H
#define IMAGE_RECOVERY_GENETIC_H

#include "src/algorithm/datamanager.h"
#include "src/data-structures/simplelist.h"
#include "src/data-structures/simplenode.h"

#include <QDebug>
#include <QImage>
#include <QList>
#include <QRgb>
#include <QVector>

using namespace std;

/**
 * @struct Subject
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
 * @class Genetic
 * @brief
 * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
 */
class Genetic {

private:
    SimpleList<QList<Chromosome>> generation; /**<  */
    QList<Chromosome> population; /**< List of possible frames as solutions to the missing frame. */
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
     */
    void geneticAlgorithm();

    /**
     * @fn void fitness()
     * @brief
     * @param gens
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     */
    void fitness(SimpleList<SimpleList<Chromosome>> gens);

    /**
     * @fn void selection()
     * @brief
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     */
    void selection();

    /**
     * @fn void crossover()
     * @brief
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     */
    void crossover();

    /**
     * @fn void mutation()
     * @brief
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     */
    void mutation();

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