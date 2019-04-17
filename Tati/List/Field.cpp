#include "Field.h"

Field::Field() {
    this->empty = true;
    g = 0;
    h = 0;
    f = 0;
    i = 0;
    j = 0;
}

/*! Funcion que sera necesaria para luego agregar obstaculos */
bool Field::addObstacle() {
    return false;
}

bool Field::isEmpty() {
    return empty;
}
