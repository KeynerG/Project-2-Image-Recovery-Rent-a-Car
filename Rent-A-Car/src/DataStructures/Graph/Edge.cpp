#include "Edge.h"


Edge::Edge() {
    this->id = "";
    this->origin = Vertex();
    this->destiny = Vertex();
    this->weight = 0;
}

Edge::Edge(string id, Vertex origin, Vertex destiny) {
    this->id = id;
    this->origin = origin;
    this->destiny = destiny;
    this->weight = 0;
}

Edge::Edge(string id, Vertex origin, Vertex destiny, int weight) {
    this->id = id;
    this->origin = origin;
    this->destiny = destiny;
    this->weight = weight;
}


const string &Edge::getId() const {
    return id;
}

void Edge::setId(const string &id) {
    Edge::id = id;
}

Vertex Edge::getOrigin() const {
    return origin;
}

void Edge::setOrigin(Vertex origin) {
    Edge::origin = origin;
}

Vertex Edge::getDestiny() const {
    return destiny;
}

void Edge::setDestiny(Vertex destiny) {
    Edge::destiny = destiny;
}

int Edge::getWeight() const {
    return weight;
}

void Edge::setWeight(int weight) {
    Edge::weight = weight;
}
