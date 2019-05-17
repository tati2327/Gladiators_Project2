#ifndef A_PATHFINDING_H
#define A_PATHFINDING_H

#include "Field.h"
#include "List.h"
#include "Matrix.h"

class Pathfinding {
    public:
        Pathfinding();

        explicit Pathfinding(Matrix<Field>& board);

        List<Field> openSet;/*!Lista abierta */
        List<Field> closeSet;/*!Lista cerrada */
        List<string> solution;/*!String con la ruta */
        Field *start;/*!Posición inical en el tablero */
        Field *end; /*!Posición final en el tablero */
        int time; /*!Tiempo que se tarda el correr el algoritmo */
        int rows, cols;/*!Fila y Columna */
        Matrix<Field> *board;/*!Tablero */

        /*!
         * addNeightbors añade los vecinos de un field
         * @param _field
         */
        void addNeighbors(Field *_field);

        /*!
         * heuristic calcula el h
         * @param a
         * @param b
         * @return
         */
        int heuristic(Field a, Field b);
        bool makeRoute();

        /*!
         * cleanAll borra todos los elementos de la lista
         */
        void cleanAll();
};


#endif //A_PATHFINDING_H
