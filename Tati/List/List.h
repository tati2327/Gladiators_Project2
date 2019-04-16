#ifndef LIST_LIST_H
#define LIST_LIST_H

#include <iostream>
#include "Node.h"

template<typename T>
class List {
    public:
        Node<T> *first;
        Node<T> *last;

        List();
        void add(T data);
        T getData(int index);
        T operator [](int index);
};

#include "List_def.h"

#endif //LIST_LIST_H
