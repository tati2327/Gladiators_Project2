#ifndef LIST_NODE_H
#define LIST_NODE_H

template<typename T>
struct Node {
    Node<T>* next;
    T data;
};

#endif //LIST_NODE_H
