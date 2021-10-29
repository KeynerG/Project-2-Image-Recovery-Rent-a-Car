#ifndef IMAGE_RECOVERY_SIMPLENODE_H
#define IMAGE_RECOVERY_SIMPLENODE_H

using namespace std;

/**
 * @class SimpleNode
 * @brief
 * @author <a href="https://github.com/JoseAndres216">Jose A. Rodríguez Rojas</a>
 */
template<class T>
class SimpleNode {

public:

    SimpleNode<T> *next;
    T data;

    SimpleNode();

    SimpleNode<T> *getNext();

    void setNext(SimpleNode<T> *next);

    T getData();

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

#endif //IMAGE_RECOVERY_SIMPLENODE_H