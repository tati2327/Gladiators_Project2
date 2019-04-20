#include <iostream>
#include "Field.h"
#include "Pathfinding.h"
#include "Matrix.h"

int main() {
    Matrix<Field> m = Matrix<Field >(3,3);

    Pathfinding p = Pathfinding(m);
    p.makeRoute();

    return 0;
}