#include "Field.h"

Field::Field() {
    this->empty = true;
}

/*! Funcion que sera necesaria para luego agregar obstaculos */
bool Field::addObstacle() {
    return false;
}

bool Field::isEmpty() {
    return empty;
}
