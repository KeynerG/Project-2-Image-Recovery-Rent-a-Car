#ifndef RENT_A_CAR_SIMPLELIST_H
#define RENT_A_CAR_SIMPLELIST_H

#include <iostream>

#include "SimpleNode.h"

using namespace std;

template<class T>

class SimpleList {
public:
    SimpleNode<T> *head;
    SimpleNode<T> *tail;
    int len;

    SimpleList<T>();

    SimpleNode<T> *getHead();

    void setHead(SimpleNode<T> *head);

    SimpleNode<T> *getTail();

    void setTail(SimpleNode<T> *tail);

    void addNodeAtStart(T data);

    void addNodeAt(int index, T data);

    void addNodeAtEnd(T data);

    void addNodeAtEnd(SimpleNode<T> *node);

    T getNodeIn(int index);

    void deleteFirstNode();

    void deleteNodeAt(int index);

    void deleteNode(SimpleNode<T> *nodeToDelete);

    void deleteLastNode();

    void clearList();

    void printList();
};

template<class T>
SimpleList<T>::SimpleList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->len = 0;
}

template<class T>
SimpleNode<T> *SimpleList<T>::getHead() {
    return this->head;
}

template<class T>
void SimpleList<T>::setHead(SimpleNode<T> *head) {
    this->head = head;
}

template<class T>
SimpleNode<T> *SimpleList<T>::getTail() {
    return this->tail;
}

template<class T>
void SimpleList<T>::setTail(SimpleNode<T> *tail) {
    this->tail = tail;
}


template<class T>
void SimpleList<T>::addNodeAt(int index, T data) {

}

template<class T>
void SimpleList<T>::addNodeAtStart(T data) {
    if (!this->head) {
        this->head = new SimpleNode<T>;
        this->head->data = data;
        this->head->next = nullptr;
        this->tail = this->head;
    } else {
        SimpleNode<T> *aux = this->head;
        this->head = new SimpleNode<T>;
        this->head->data = data;
        this->head->next = aux;
    }
    this->len++;
}

template<class T>
void SimpleList<T>::addNodeAtEnd(T data) {
    if (!this->head) {
        // The list is empty
        this->head = new SimpleNode<T>;
        this->head->data = data;
        this->head->next = nullptr;
        this->tail = this->head;
    } else {
        // The list isn't empty
        if (this->tail == this->head) {
            // The list has one element
            this->tail = new SimpleNode<T>;
            this->tail->data = data;
            this->tail->next = nullptr;
            this->head->next = this->tail;
        } else {
            // The list has more than one element
            SimpleNode<T> *insdata = new SimpleNode<T>;
            insdata->data = data;
            insdata->next = nullptr;
            this->tail->next = insdata;
            this->tail = insdata;
        }
    }
    this->len++;
}

template<class T>
void SimpleList<T>::addNodeAtEnd(SimpleNode<T> *node) {
    this->tail->setNext(node);
    this->tail = node;
    this->len++;
}

template<class T>
T SimpleList<T>::getNodeIn(int index) {
    if (index == 0) {
        // Get the first element
        return this->head->data;
    } else {
        // Get the index'th element
        SimpleNode<T> *aux = this->head;
        for (int i = 0; i < index; ++i) {
            aux = aux->next;
        }
        return aux->data;
    }
}

template<class T>
void SimpleList<T>::deleteFirstNode() {
    if(this->len >= 2){
        SimpleNode<T> *aux = this->head;
        this->head = this->head->getNext();
        aux->setNext(nullptr);
        delete(aux);
    }else{
        this->head = nullptr;
        this->tail = nullptr;
    }
    this->len--;
}

template<class T>
void SimpleList<T>::deleteNodeAt(int index) {

}

template<class T>
void SimpleList<T>::deleteNode(SimpleNode<T> *nodeToDelete) {
    if(nodeToDelete == this->head){
        deleteFirstNode();
    }else if(nodeToDelete == this->tail){
        deleteLastNode();
    }else{
        SimpleNode<T> *aux = this->head;
        while(nodeToDelete != aux->getNext()){
            aux = aux->getNext();
        }
        SimpleNode<T> *del = aux->getNext();
        aux->setNext(aux->getNext()->getNext());
        del->setNext(nullptr);
        delete(del);
        this->len--;
    }

}

template<class T>
void SimpleList<T>::deleteLastNode() {
    if(this->len >= 2){
        SimpleNode<T> *aux = this->head;
        while(aux->getNext()->getNext() != nullptr){
            aux = aux->getNext();
        }
        this->tail = aux;
        delete(aux->getNext());
        aux->setNext(nullptr);
    }else{
        this->head = nullptr;
        this->tail = nullptr;
    }
    this->len--;
}

template<class T>
void SimpleList<T>::clearList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->len = 0;
}

template<class T>
void SimpleList<T>::printList() {
    SimpleNode<T> *aux = this->head;
    while (aux != nullptr) {
        try {
            cout << "Node data: " << aux->getData() << ", ";
            aux = aux->next;
        } catch (error_code e) {
            cout << "Error caught: " << e << endl;
        }
    }
}

#endif //RENT_A_CAR_SIMPLELIST_H
