#include "Pathfinding.h"

Pathfinding::Pathfinding(Matrix<Field> _board) :board(_board) {
    /*! Se crea la matriz con datos de tipo field*/
    this->board = _board;
    /*! Se inicializa el conjunto abierto y cerrado*/
    openSet = new List<Field>;
    closeSet = new List<Field>;
    /*! Se le agrega a cada campo de la matriz sus vecinos*/
    rows = 3;
    cols = 3;
    /*! Primero cambio los i y j del tablero por un numero de fila y una columna*/
    Field *_field = new Field;
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            _field->i = i;
            _field->j = j;
            board.setData(i, j, *_field);
        }
    }
    /*! Luego a cada campo le agrego sus respectivos vecinos*/
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            _field = &board.operator()(i,j);
            addNeighbors(_field);
            //for que NO ES NECESARIO, SOLO PARA VERIFICAR DATOS
            for (int x = 0; x < _field->neighbors.size(); x++) {
                cout << "Mi vecino es " << _field->neighbors.getData(x).i << _field->neighbors.getData(x).j << endl;
            }
        }
    }
    /*! Donde fializa la ruta */
    this->end.i = 9;
    this->end.j = 9;
}

void Pathfinding::addNeighbors(Field *_field) {
    int i = _field->i;
    int j = _field->j;

    cout<<"Se van agregar los vecinos de "<<i<< " "<< j<<endl;
    if(i < rows-1){
        _field->neighbors.add(board.operator()(i+1,j));
    }if(i>0){
        _field->neighbors.add(board.operator()(i-1,j));
    }if(j < cols-1){
        _field->neighbors.add(board.operator()(i,j+1));
    }if(j > 0){
        _field->neighbors.add(board.operator()(i,j-1));
    }
}

int Pathfinding::heuristic(Field a, Field b) {
    int d  = abs(b.i - a.i) + abs(b.j - a.j);
    return d;
}

bool Pathfinding::makeRoute() {
    openSet->add(start);
    int winner = 0; /*!< Nodo con el f más bajo */
    while(openSet->size()>0){

        /*! Busca en la lista abierta el nodo con el f más bajo*/
        for(int i =0; i < openSet->size(); i++){
            if( openSet[i].getData(i).f < openSet->getData(winner).f){
                winner = i;
            }
        }

        Field *current;
        current = &openSet->getNode(winner)->data;

        /*! Verifica que el nodo winner sea o no el final*/
        if((current->i == end.i) && (current->j == end.j)){
            cout<<"Se encontró la mejor ruta!!!"<<endl;
            return true;
        }

        /*! Se remueve de la lista abierta winner*/
        cout<<"OPEN "<<endl;
        openSet->deleteNode(*current);
        /*! Pero éste se agrega a la lista cerrada*/
        closeSet->add(*current);

        List<Field> neighbors = current->neighbors;
        for(int i = 0; i < neighbors.size(); i++){
            Field neighbor = neighbors[i];

            bool inCloseSet = false;
            for(int k = 0; k < closeSet->size(); k++){
                if(closeSet->getData(k).i == neighbor.i && closeSet->getData(k).j == neighbor.j)
                    return true;
            }
            if(!inCloseSet){
                int tempG = current->g +10;
            }
        }
    }
    cout<<"No hay solución"<<endl;
    return false;
}
