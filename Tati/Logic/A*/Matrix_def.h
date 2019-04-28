template<typename T>
Matrix<T>::Matrix( int rows, int cols){
    setRow(rows);
    setCol(cols);

    data = new T*[rows];
    for (int i = 0; i < row; i++) {
        data[i] = new T [cols];
    }

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < cols; j++) {
            myData.i = i;
            myData.j = j;
            data[i][j] = myData;
        }
    }
}

template <class T>
void Matrix<T>::show (){
    int i,j;

    for (i=0;i < row;i++){
        for(j=0;j < col;j++){
            cout<<data[i][j]<< "  ";
        }
        cout<<endl;
    }
}

template<class T>
T& Matrix<T>::operator()(int row, int col){
    return data[row][col];
}

template<typename T>
void Matrix<T>::setData(int row, int col, T _data){
    this->data[row][col] = _data;
}

template<typename T>
void Matrix<T>::setRow(int r){
    row = r;
}

template<typename T>
void Matrix<T>::setCol(int c){
    col = c;
}