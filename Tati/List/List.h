#ifndef LIST_LIST_H
#define LIST_LIST_H

#include <iostream>
#include "Node.h"

template<typename T>
class List {
    public:
        Node<T> *first; /*!< Primer elemento de la lista*/
        Node<T> *last; /*!< Ultimo elemento de la lista*/
        Node<T> *curr;

        /*!
         *
         */
        List();

        /*!
         *
         * @param data
         */
        void add(T data);

        void deleteNode(T data);

        /*!
         *
         * @param index
         * @return
         */
        T getData(int index);

        /*!
         *
         */
        void show();

        /*!
         *
         * @return
         */
        int size();

        /*!
         *
         * @param index
         * @return
         */
        T operator [](int index);
};

#include "List_def.h"

#endif //LIST_LIST_H
