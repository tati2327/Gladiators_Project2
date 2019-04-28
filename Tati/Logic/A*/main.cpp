#include <iostream>
#include "Field.h"
#include "Pathfinding.h"
#include "Matrix.h"

int main() {

    Matrix<Field> m = Matrix<Field >(10,10);

    Pathfinding p = Pathfinding(m);

    m.operator()(0,1).addObstacle();
    m.operator()(2,1).addObstacle();
    m.operator()(3,2).addObstacle();
    m.operator()(1,3).addObstacle();

    p.makeRoute();

    return 0;
}