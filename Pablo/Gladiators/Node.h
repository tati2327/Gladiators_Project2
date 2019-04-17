//
// Created by pablo on 16/04/19.
//

#ifndef GLADIATORS_NODE_H
#define GLADIATORS_NODE_H


template<typename T>
class Node {
public:
    Node<T>* next;
    T data;

    T getValue();
    void setData(T data);
    void setNode(Node<T> _node);
    Node<T> * getNext();
};

#include "Node_def.h"

#endif //LIST_NODE_H