#ifndef RENT_A_CAR_VERTEX_H
#define RENT_A_CAR_VERTEX_H

#include <iostream>

using namespace std;

/**
 * @class Vertex
 * @brief Class for saving each graph node data.
 */
class Vertex {
private:
    string id;
    string name;
public:

    /**
     * @brief Class default constructor.
     */
    Vertex();

    /**
     * @brief Class constructor.
     * @param id
     * @param name
     */
    Vertex(string id, string name);

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
     * @brief name getter.
     * @return
     */
    const string &getName() const;

    /**
     * @brief name setter.
     * @param name
     */
    void setName(const string &name);
};


#endif //RENT_A_CAR_VERTEX_H
