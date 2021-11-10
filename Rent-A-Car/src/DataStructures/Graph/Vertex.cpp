#include "Vertex.h"

Vertex::Vertex() {
    this->id = "";
    this->name = "";
}

Vertex::Vertex(string id, string name) {
    this->id = id;
    this->name = name;
}

const string &Vertex::getId() const {
    return id;
}

void Vertex::setId(const string &id) {
    Vertex::id = id;
}

const string &Vertex::getName() const {
    return name;
}

void Vertex::setName(const string &name) {
    Vertex::name = name;
}