#ifndef A_MATRIX_H
#define A_MATRIX_H

#include "List.h"

template<typename T>
class Matrix {
    private:
        int row;/*!Fila del tablero */
        int col;/*!Columna del tablero */
        T **data;/*!puntero doble de la matriz */
        T myData;/*!data */

    public:
        Matrix();
        Matrix(int rows, int cols);

        /*!
         * setRow agrega el valor de fila
         * @param r
         */
        void setRow(int r);

        /*!
         * setCol agrega el valor de columna
         * @param c
         */
        void setCol(int c);

        /*!
         * setData agrega la informacion a cada Field
         * @param row
         * @param col
         * @param _data
         */
        void setData(int row, int col, T _data);

        /*!
         * show se encarga de mostrar la matriz
         */
        void show();

        T& operator()(int row, int col);
};

#include "Matrix_def.h"

#endif //A_MATRIX_H
