#ifndef IMAGE_RECOVERY_GENETIC_H
#define IMAGE_RECOVERY_GENETIC_H

#include "src/data-structures/simplelist.h"
#include "src/data-structures/simplenode.h"

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
     * @fn void createXML()
     * @brief
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     */
    void createXML();

    /**
     * @fn void createImage()
     * @brief
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     */
    void createImage();
};

#endif //IMAGE_RECOVERY_GENETIC_H