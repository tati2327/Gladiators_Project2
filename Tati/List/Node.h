#ifndef LIST_NODE_H
#define LIST_NODE_H

template<typename T>
class Node {
    public:
        Node<T>* next;
        T data;

        T getValue();
        Node<T> * getNext();
};

#include "Node_def.h"

#endif //LIST_NODE_H
