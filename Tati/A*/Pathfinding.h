#ifndef A_PATHFINDING_H
#define A_PATHFINDING_H

#include "Field.h"
#include "List.h"
#include "Matrix.h"

class Pathfinding {
public:
    Pathfinding(Matrix<Field>& board);

    List<Field> openSet;
    List<Field> closeSet;

    Field *start;
    Field *end;

    int rows, cols;

    Matrix<Field> *board;

    void addNeighbors(Field *_field);
    int heuristic(Field a, Field b);
    bool makeRoute();
};


#endif //A_PATHFINDING_H
