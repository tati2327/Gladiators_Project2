#ifndef LIST_FIELD_H
#define LIST_FIELD_H


#include "List.h"

class Field {
    public:
        int f, g, h, i, j;
        bool empty;

        Field();

        bool addObstacle();
        bool isEmpty();

        List<Field> neighbors;
};


#endif //LIST_FIELD_H
