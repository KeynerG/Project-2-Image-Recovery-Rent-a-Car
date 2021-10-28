#ifndef RENT_A_CAR_SIMPLENODE_H
#define RENT_A_CAR_SIMPLENODE_H

#include <iostream>

using namespace std;

/**
 * @class SimpleNode
 * @brief Class for a simply linked node.
 * @tparam T
 */
template<class T>
class SimpleNode {
public:
    SimpleNode<T> *next;
    T data;

    /**
     * @brief Class default constructor.
     */
    SimpleNode();

    /**
     * @brief next getter.
     * @return next
     */
    SimpleNode<T> *getNext();

    /**
     * @brief next setter.
     * @param next
     */
    void setNext(SimpleNode<T> *next);

    /**
     * @brief data getter.
     * @return data
     */
    T getData();

    /**
     * @brief data setter.
     * @param data
     */
    void setData(T data);
};

template<class T>
SimpleNode<T>::SimpleNode() {
    this->next = nullptr;
}

template<class T>
T SimpleNode<T>::getData() {
    return this->data;
}

template<class T>
void SimpleNode<T>::setData(T data) {
    this->data = data;
}

template<class T>
SimpleNode<T> *SimpleNode<T>::getNext() {
    return this->next;
}

template<class T>
void SimpleNode<T>::setNext(SimpleNode<T> *next) {
    this->next = next;
}

#endif //RENT_A_CAR_SIMPLENODE_H
