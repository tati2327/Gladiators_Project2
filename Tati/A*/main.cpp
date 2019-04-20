#include <iostream>
#include "Field.h"
#include "Pathfinding.h"
#include "Matrix.h"

int main() {
    Matrix<Field> m = Matrix<Field >(3,3);

    Pathfinding p = Pathfinding(m);

    m.operator()(0,1).addObstacle();

    p.makeRoute();

    return 0;
}