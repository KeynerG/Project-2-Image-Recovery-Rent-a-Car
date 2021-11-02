#ifndef IMAGE_RECOVERY_GENETIC_H
#define IMAGE_RECOVERY_GENETIC_H

#include "src/algorithm/datamanager.h"
#include "src/data-structures/simplelist.h"
#include "src/data-structures/simplenode.h"

#include <QDebug>
#include <QImage>

using namespace std;

/**
 * @class Genetic
 * @brief
 * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
 */
class Genetic {

private:

    SimpleList<SimpleList<SimpleNode<int>>> generationsList;
    SimpleList<SimpleNode<int>> generation;

public:

    /**
     * @fn void createGeneration()
     * @brief
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     */
    void createGeneration();

    /**
     * @fn void fitness()
     * @brief
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     */
    void fitness();

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