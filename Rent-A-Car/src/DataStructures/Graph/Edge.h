#ifndef RENT_A_CAR_EDGE_H
#define RENT_A_CAR_EDGE_H

#include <iostream>

#include "Vertex.h"

using namespace std;

/**
 * @class Edge
 * @brief Class for saving each connection data.
 */
class Edge {
private:
    string id;
    Vertex origin;
    Vertex destiny;
    int weight;

public:
    /**
     * @brief Class default constructor.
     */
    Edge();

    /**
     * @brief Class constructor.
     * @param id
     * @param origin
     * @param destiny
     */
    Edge(string id, Vertex origin, Vertex destiny);

    /**
     * @brief Class constructor.
     * @param id
     * @param origin
     * @param destiny
     * @param weight
     */
    Edge(string id, Vertex origin, Vertex destiny, int weight);

    /**
     * @brief id getter.
     * @return id
     */
    const string &getId() const;

    /**
     * @brief id setter.
     * @param id
     */
    void setId(const string &id);

    /**
     * @brief origin getter.
     * @return origin
     */
    Vertex getOrigin() const;

    /**
     * @brief origin setter.
     * @param origin
     */
    void setOrigin(Vertex origin);

    /**
     * @brief destiny getter.
     * @return destiny
     */
    Vertex getDestiny() const;

    /**
     * @brief destiny setter.
     * @param destiny
     */
    void setDestiny(Vertex destiny);

    /**
     * @brief weight getter.
     * @return weight
     */
    int getWeight() const;

    /**
     * @brief weight setter.
     * @param weight
     */
    void setWeight(int weight);
};


#endif //RENT_A_CAR_EDGE_H
