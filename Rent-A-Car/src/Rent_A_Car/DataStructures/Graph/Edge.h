#ifndef RENT_A_CAR_EDGE_H
#define RENT_A_CAR_EDGE_H

#import "Vertex.h"

#import <iostream>

using namespace std;

class Edge {
private:
    string id;
    Vertex origin;
    Vertex destiny;
    int weight;

public:
    Edge();

    Edge(string id, Vertex origin, Vertex destiny);

    Edge(string id, Vertex origin, Vertex destiny, int weight);

    const string &getId() const;

    void setId(const string &id);

    Vertex getOrigin() const;

    void setOrigin(Vertex origin);

    Vertex getDestiny() const;

    void setDestiny(Vertex destiny);

    int getWeight() const;

    void setWeight(int weight);
};


#endif //RENT_A_CAR_EDGE_H
