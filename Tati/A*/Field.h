#ifndef A_FIELD_H
#define A_FIELD_H

#include "List.h"

class Field {
public:
    int f, g, h, i, j;
    bool empty;

    Field();

    bool addObstacle();
    bool isEmpty();

    List<Field*> neighbors;
    bool equal(Field object);

    void deleteField(Field _node, List<Field>& _list);
};


#endif //A_FIELD_H
