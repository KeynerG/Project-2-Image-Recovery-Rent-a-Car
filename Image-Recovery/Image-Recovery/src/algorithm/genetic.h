#ifndef IMAGE_RECOVERY_GENETIC_H
#define IMAGE_RECOVERY_GENETIC_H

#include "src/algorithm/datamanager.h"
#include "src/data-structures/simplelist.h"
#include "src/data-structures/simplenode.h"

#include <QDebug>
#include <QImage>

struct Subject{
    int id;
    QVector<QRgb> frame;
    int similarity;
};

using namespace std;

/**
 * @class Genetic
 * @brief
 * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
 */
class Genetic {

private:

    SimpleList<SimpleList<Subject>> generationsList;
    SimpleList<Subject> generation;
    int precision;

public:

    bool firstTime = false;

    /**
     * @fn void geneticAlgorithm()
     * @brief
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     */
    void geneticAlgorithm();

    /**
     * @fn void fitness()
     * @brief
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     */
    void fitness(SimpleList<SimpleList<Subject>> gens);

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
      * @fn bool checkGenerationNumber()
      * @brief
      * @param generationID
      * @return
      * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
      */
    bool checkGenerationNumber(int &generationID);

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