#ifndef A_MATRIX_H
#define A_MATRIX_H

#include "List.h"

template<typename T>
class Matrix {
private:
    int row;
    int col;
    T **data;
    T myData;

public:
    Matrix(int rows, int cols);

    void setRow(int r);
    void setCol(int c);
    void setData(int row, int col, T _data);

    T& operator()(int row, int col);
    void show();
};

#include "Matrix_def.h"

#endif //A_MATRIX_H
