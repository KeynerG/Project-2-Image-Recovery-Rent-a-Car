#ifndef IMAGE_RECOVERY_GENETIC_H
#define IMAGE_RECOVERY_GENETIC_H

#include "src/data-structures/SimpleList.h"
#include "src/data-structures/SimpleNode.h"

using namespace std;

class Genetic {

private:

    SimpleList <SimpleList<SimpleNode <int>>> generationsList;
    SimpleList <SimpleNode<int>> generation;

public:

    void createGeneration();

    void fitness();

    void selection();

    void crossover();

    void mutation();

    void createXML();

};

#endif //IMAGE_RECOVERY_GENETIC_H