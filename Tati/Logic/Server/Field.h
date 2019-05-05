#ifndef A_FIELD_H
#define A_FIELD_H

#include "List.h"

class Field {
    public:
        int f, g, h, i, j;
        bool inLine, inDiagonal, obstacle;
        string father;
        bool initG;

        Field();

        void setInLine(bool inLine);
        void setInDiagonal(bool inDiagonal);

        bool addObstacle();
        bool isObstacle();

        List<Field*> neighbors;
        bool equal(Field object);
        void deleteField(Field _node, List<Field>& _list);
};

#endif //A_FIELD_H
