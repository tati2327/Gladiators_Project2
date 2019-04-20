#include "Pathfinding.h"

Pathfinding::Pathfinding(Matrix<Field> _board) :board(_board) {
    /*! Se crea la matriz con datos de tipo field*/
    this->board = _board;

    /*! Se inicializan datos*/
    start = new Field;
    end = new Field;
    rows = 3;
    cols = 3;

    /*! Donde fializa la ruta */
    end->i = 9;
    end->j = 9;

    /*! Donde empieza la ruta*/
    start = &board.operator()(0,0);
    end = &board.operator()(rows-1,cols-1);

    Field *_field;
    /*! Luego a cada campo le agrego sus respectivos vecinos*/
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            _field = &board.operator()(i,j);
            addNeighbors(_field);
        }
    }

    cout<<"vecinos "<<endl;
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout<<"VECINOS DE "<<board.operator()(i,j).i<<" "<<board.operator()(i,j).j<<endl;
            for(int x = 0; x <board.operator()(i,j).neighbors.size(); x++)
                cout<<board.operator()(i,j).neighbors.getNode(x)->data->i<<board.operator()(i,j).neighbors.getNode(x)->data->j<<endl;
            cout<<"G "<<board.operator()(i,j).g<<" H "<<board.operator()(i,j).h<<" F "<<board.operator()(i,j).f<<endl;
        }
    }
}

void Pathfinding::addNeighbors(Field *_field) {
    int i = _field->i;
    int j = _field->j;

    Field *temp;
    cout<<"Se van agregar los vecinos de "<<i<< " "<< j<<endl;
    if(i < rows-1){
        temp = &(board.operator()(i+1,j));
        _field->neighbors.add(temp);
    }if(i>0){
        temp = &board.operator()(i-1,j);
        _field->neighbors.add(temp);
    }if(j < cols-1){
        temp = &board.operator()(i,j+1);
        _field->neighbors.add(temp);
    }if(j > 0){
        temp = &board.operator()(i,j-1);
        _field->neighbors.add(temp);
    }
}

/*! Calculo del H */
int Pathfinding::heuristic(Field a, Field b) {
    int d  = abs(b.i - a.i) + abs(b.j - a.j);
    cout<<"HEURISTICO "<<d<<endl;
    return d;
}

bool Pathfinding::makeRoute() {
    openSet.add(*start);
    int winner; /*!< Nodo con el f más bajo */

    /*! Mientras el conjunto abierto tenga elementos se ejecuta el algoritmo A* */
    while(openSet.size()>0){
        /*! Busca en la lista abierta el nodo con el f más bajo*/

        winner = 0;
        cout<<"---------------------EMPIEZA EL BUCLE" <<endl;
        cout<<"LA OPENSET ES DE TAMAÑO "<<openSet.size()<<endl;
        cout<<"LA CLOSESET ES DE TAMAÑO "<<closeSet.size()<<endl;

        for(int g = 0; g < openSet.size(); g++){
            cout<<"LOS NODOS DE LA OPENSET SON: "<<&openSet.getNode(g)->data<<endl;
            cout<<openSet.getData(g).i<<" "<<openSet.getData(g).j<<" Y MI VALOR DE F ES "<<openSet.getNode(g)->data.f<<endl;
            cout<<"VECINOS "<<openSet.getNode(g)->data.neighbors.size()<<endl;
            for(int i = 0; i<openSet.getNode(g)->data.neighbors.size(); i++){
                cout<<"SON "<<openSet.getNode(g)->data.neighbors.getNode(i)->data<<endl;
            }
        }

        cout<<"BUSCANDO MI WINNER"<<endl;
        for(int i =0; i < openSet.size(); i++){
            cout<<"i es "<<i<<endl;
            if( openSet.getNode(i)->data.f <= openSet.getNode(winner)->data.f){
                winner = i;
            }
        }

        /*! Es necesario para eliminar los nodos del conjunto abierto*/
        Field temp = openSet.getNode(winner)->data;
        Field *current = &temp;

        cout<<"MI CURRENT ES "<<current->i<<" "<<current->j<<" DIRECCION "<<current<<endl;
        cout<<" f "<<current->f<<" g "<<current->g<<" h "<<current->h<<endl;
        cout<<"VECINOS DE CURRENT "<<current->neighbors.size()<<" UN VECINO DE CURR TIENE VECINOS "<<current->neighbors.getNode(0)->data->neighbors.size()<<endl;

        /*! Verifica que el nodo winner sea o no el final
         * IMPORTANTE: Si entra en ese if significa que ya hay una ruta
         * */
        if((current->i == end->i) && (current->j == end->j)){
            cout<<"Se encontró la mejor ruta!!!"<<endl;
            string strTemp = " ";
            for (int i = 0;i<closeSet.size(); i++){
                strTemp += "["+to_string(closeSet.getNode(i)->data.i)+","+to_string((closeSet.getNode(i)->data.j))+"]";
            }
            cout<<strTemp<<endl;
            return true;
        }

        /*! Se remueve de la lista abierta winner*/
        current->deleteField(temp, openSet);
        /*! Pero éste se agrega a la lista cerrada*/
        closeSet.add(*current);
        cout<<"Se agrego un nodo a la lista cerrada "<<closeSet.getNode(winner)->data.i<<" "<<closeSet.getNode(winner)->data.j<<endl;

        //Evaluo vecinos
        for(int i = 0; i < current->neighbors.size(); i++){
            //Field neighbor = *current->neighbors.getNode(i)->data;

            cout<<"VECINO CURR "<<current->neighbors.getNode(i)->data<<" VECINO "<<current->neighbors.getNode(i)->data<<endl;
            cout<<"VECINO A EVALUAR "<<current->neighbors.getNode(i)->data->i<<" "<<current->neighbors.getNode(i)->data->j<<" VECINOS "<<current->neighbors.getNode(i)->data->neighbors.size()<<endl;

            /*! Verifica que el vecino a evaluar NO este en el conjunto cerrado cerrada*/
            bool inCloseSet = false;
            for(int k = 0; k < closeSet.size(); k++){
                if(closeSet.getData(k).i == current->neighbors.getNode(i)->data->i &&
                   closeSet.getData(k).j == current->neighbors.getNode(i)->data->j)
                    inCloseSet = true;
            }

            /*! Si el vecino no esta en el conjunto cerrado entonces lo evalua*/
            if(!inCloseSet){
                int inLine = 10;
                cout<<"LA G ES "<<inLine<<endl;
                cout<<"EL CURRENT TIENE G DE "<<current->g<<endl;

                bool inOpenSet = false;
                for(int k = 0; k < openSet.size(); k++){
                    if(openSet.getData(k).i == current->neighbors.getNode(i)->data->i &&
                       openSet.getData(k).j == current->neighbors.getNode(i)->data->j)
                        inOpenSet = true;
                }

                if(!inOpenSet){
                    current->neighbors.getNode(i)->data->g = inLine;
                    current->neighbors.getNode(i)->data->h = this->heuristic(*current->neighbors.getNode(i)->data,*end);
                    current->neighbors.getNode(i)->data->f = current->neighbors.getNode(i)->data->g + current->neighbors.getNode(i)->data->h;
                    openSet.add(*current->neighbors.getNode(i)->data);
                    cout<<"------------------------------------------------"<<endl;
                    cout<<"TAMAÑO DE LA LISTA "<<openSet.size()<<endl;
                    for(int g = 0; g < openSet.size(); g++){
                        cout<<"g es "<<g<<endl;
                        cout<<"LOS NODOS DE LA OPENSET SON: "<<endl;
                        cout<<openSet.getData(g).i<<" "<<openSet.getData(g).j<<" Y MI VALOR DE F ES "<<openSet.getNode(g)->data.f<<endl;
                        cout<<"VECINOS SON "<<openSet.getNode(g)->data.neighbors.size()<<endl;
                    }
                }else{
                    continue;
                }
            }
        }
    }
    /*! Si el conjunto abierto ya no tiene elementos por evaluar significa que no se encontró la ruta*/
    cout<<"No hay solución"<<endl;
    return false;
}