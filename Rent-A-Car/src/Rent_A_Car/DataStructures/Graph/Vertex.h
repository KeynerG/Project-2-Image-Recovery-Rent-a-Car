#ifndef RENT_A_CAR_VERTEX_H
#define RENT_A_CAR_VERTEX_H

#include <iostream>

using namespace std;

class Vertex {
private:
    string id;
    string name;

public:

    Vertex();

    Vertex(string id, string name);

    const string &getId() const;

    void setId(const string &id);

    const string &getName() const;

    void setName(const string &name);
};


#endif //RENT_A_CAR_VERTEX_H
