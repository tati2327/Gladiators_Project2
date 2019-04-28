#include "Pathfinding.h"
#include <chrono>

Pathfinding::Pathfinding() {

}

Pathfinding::Pathfinding(Matrix<Field>& _board) :board(&_board) {
    /*! Se crea la matriz con datos de tipo field*/
    this->board = &_board;

    /*! Se inicializan datos*/
    start = new Field;
    end = new Field;
    rows = 10;
    cols = 10;

    /*! Donde empieza y finaliza la ruta*/
    start = &board->operator()(0,0);
    end = &board->operator()(rows-1,cols-1);
}

void Pathfinding::addNeighbors(Field *_field) {

    int i = _field->i;
    int j = _field->j;

    Field *temp;
    /*! Calcula los vecinos en vertical y horizontal */
    if(i < rows-1){
        temp = &(board->operator()(i+1,j));
        temp->setInLine(true);
        _field->neighbors.add(temp);
    }if(i>0){
        temp = &board->operator()(i-1,j);
        temp->setInLine(true);
        _field->neighbors.add(temp);
    }if(j < cols-1){
        temp = &board->operator()(i,j+1);
        temp->setInLine(true);
        _field->neighbors.add(temp);
    }if(j > 0){
        temp = &board->operator()(i,j-1);
        temp->setInLine(true);
        _field->neighbors.add(temp);
    }
    /*! Calcula los vecinos en diagonal */
    if(i > 0 && j > 0){
        temp = &board->operator()(i-1,j-1);
        temp->setInDiagonal(true);
        _field->neighbors.add(temp);
    }if(i < rows-1 && j > 0){
        temp = &board->operator()(i+1,j-1);
        temp->setInDiagonal(true);
        _field->neighbors.add(temp);
    }if(i > 0 && j < cols-1){
        temp = &board->operator()(i-1,j+1);
        temp->setInDiagonal(true);
        _field->neighbors.add(temp);
    }if(i < rows-1 && j < cols-1){
        temp = &board->operator()(i+1,j+1);
        temp->setInDiagonal(true);
        _field->neighbors.add(temp);
    }
}

/*! Calculo del H */
int Pathfinding::heuristic(Field a, Field b) {
    int d  = abs(b.i - a.i) + abs(b.j - a.j);
    cout<<"Heuristico(H) "<<d<<endl;
    return d;
}

bool Pathfinding::makeRoute() {
    auto timeStart = std::chrono::high_resolution_clock::now();
    openSet.add(*start);
    int winner; /*!< Nodo con el f más bajo */

    /*! Mientras el conjunto abierto tenga elementos se ejecuta el algoritmo A* */
    while(openSet.size()>0){
        winner = 0;

        //for NO necesario
        for(int g = 0; g < openSet.size(); g++){
            cout<<"Los elementos en la openset son: "<<openSet.getNode(g)->data.i<<openSet.getNode(g)->data.j<<endl;
        }

        /*! Busca en la lista abierta el nodo con el f más bajo*/
        for(int i =0; i < openSet.size(); i++){
            if( openSet.getNode(i)->data.f <= openSet.getNode(winner)->data.f){
                winner = i;
            }
        }

        /*! Es necesario para eliminar los nodos del conjunto abierto*/
        Field temp = openSet.getNode(winner)->data;
        Field *current = &temp;

        //NO necesario
        cout<<"Mi current es "<<current->i<<" "<<current->j<<endl;
        cout<<" f "<<current->f<<" g "<<current->g<<" h "<<current->h<<endl;

        /*! Verifica que el nodo winner sea o no el final
         * IMPORTANTE: Si entra en ese if significa que ya hay una ruta */
        if((current->i == end->i) && (current->j == end->j)){
            closeSet.add(*end);
            cout<<"Se encontró la mejor ruta!!!"<<endl;
            string strTemp = "";
            for (int i = 0;i<closeSet.size(); i++){
                strTemp += "["+to_string(closeSet.getNode(i)->data.i)+","+to_string((closeSet.getNode(i)->data.j))+"]";
            }
            auto finish = std::chrono::high_resolution_clock::now();
            cout <<"Duración "<< chrono::duration_cast<chrono::microseconds>(finish-timeStart).count() << endl;
            cout<<strTemp<<endl;
            return true;
        }

        /*! Se remueve de la lista abierta winner*/
        current->deleteField(temp, openSet);
        /*! Pero éste se agrega a la lista cerrada*/
        closeSet.add(*current);
        cout<<"Se agrego un nodo a la lista cerrada "<<current->i<<current->j<<endl;

        /*! Calcular vecinos */
        this->addNeighbors(current);

        cout<<"Vecinos de current "<<current->neighbors.size()<<" y son: "<<endl;
        for(int i = 0; i < current->neighbors.size(); i++){
            cout<<current->neighbors.getNode(i)->data->i<<current->neighbors.getNode(i)->data->j<<endl;
        }

        /*! Evaluo vecinos*/
        for(int i = 0; i < current->neighbors.size(); i++) {

            cout << "Vecino numero " << i + 1 << " de " << current->neighbors.size() << endl;
            cout << "Vecino a evaluar " << current->neighbors.getNode(i)->data->i << " "
                 << current->neighbors.getNode(i)->data->j << endl;

            /*! Verifica que el vecino a evaluar sea o no el punto final*/
            if (current->neighbors.getData(i)->i == end->i && current->neighbors.getData(i)->j == end->j){
                closeSet.add(*end);
                cout << "Se encontró la mejor ruta!!!" << endl;
                string strTemp = " ";
                for (int j = 0; j < closeSet.size(); j++) {
                    strTemp +="["+to_string(closeSet.getNode(j)->data.i)+ "," +to_string((closeSet.getNode(j)->data.j))+"]";
                }
                auto finish = std::chrono::high_resolution_clock::now();
                cout <<"Duración "<< chrono::duration_cast<chrono::microseconds>(finish-timeStart).count() << endl;
                cout << strTemp << endl;
                return true;
            }

            /*! Verifica que el vecino a evaluar NO este en el conjunto cerrado*/
            bool inCloseSet = false;
            for(int k = 0; k < closeSet.size(); k++){
                if(closeSet.getData(k).i == current->neighbors.getNode(i)->data->i &&
                   closeSet.getData(k).j == current->neighbors.getNode(i)->data->j)
                    inCloseSet = true;
            }

            /*! Si el vecino no esta en el conjunto cerrado ni es un muro entonces lo evalua*/
            if(!inCloseSet && !current->neighbors.getNode(i)->data->isObstacle()){

                /*! Verifica que el vecino a evaluar NO este en el conjunto abierto*/
                bool inOpenSet = false;
                for(int k = 0; k < openSet.size(); k++){
                    if(openSet.getData(k).i == current->neighbors.getNode(i)->data->i &&
                       openSet.getData(k).j == current->neighbors.getNode(i)->data->j)
                        inOpenSet = true;
                }

                if(!inOpenSet){
                    /*cout<<"g = 10"<<endl;
                    current->neighbors.getNode(i)->data->g = 10;
                    current->neighbors.getNode(i)->data->h = this->heuristic(*current->neighbors.getNode(i)->data,*end);
                    current->neighbors.getNode(i)->data->f = current->neighbors.getNode(i)->data->g + current->neighbors.getNode(i)->data->h;
                    openSet.add(*current->neighbors.getNode(i)->data);*/

                    /*! Si esta en diagonal g = 14*/
                    if(current->neighbors.getNode(i)->data->inDiagonal){
                        cout<<"g = 14"<<endl;
                        current->neighbors.getNode(i)->data->g = 14;
                        current->neighbors.getNode(i)->data->h = this->heuristic(*current->neighbors.getNode(i)->data,*end);
                        current->neighbors.getNode(i)->data->f = current->neighbors.getNode(i)->data->g + current->neighbors.getNode(i)->data->h;
                        openSet.add(*current->neighbors.getNode(i)->data);
                    }else{
                        /*! Si esta en vertical u horizontal g = 10*/
                        cout<<"g = 10"<<endl;
                        current->neighbors.getNode(i)->data->g = 10;
                        current->neighbors.getNode(i)->data->h = this->heuristic(*current->neighbors.getNode(i)->data,*end);
                        current->neighbors.getNode(i)->data->f = current->neighbors.getNode(i)->data->g + current->neighbors.getNode(i)->data->h;
                        openSet.add(*current->neighbors.getNode(i)->data);
                    }
                }else{
                    cout<<"Ya esta en el conjunto abierto"<<endl;
                    continue;
                }
            }
        }
    }
    /*! Si el conjunto abierto ya no tiene elementos por evaluar significa que no se encontró la ruta*/
    cout<<"No hay solución"<<endl;
    return false;
}

