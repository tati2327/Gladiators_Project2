#include "Pathfinding.h"
#include <chrono>

Pathfinding::Pathfinding() = default;

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
        if(temp->father == "00")
            temp->father = to_string(_field->i)+ to_string(_field->j);
        _field->neighbors.add(temp);
    }if(i>0){
        temp = &board->operator()(i-1,j);
        temp->setInLine(true);
        if(temp->father == "00")
            temp->father = to_string(_field->i)+ to_string(_field->j);
        _field->neighbors.add(temp);
    }if(j < cols-1){
        temp = &board->operator()(i,j+1);
        temp->setInLine(true);
        if(temp->father == "00")
            temp->father = to_string(_field->i)+ to_string(_field->j);
        _field->neighbors.add(temp);
    }if(j > 0){
        temp = &board->operator()(i,j-1);
        temp->setInLine(true);
        if(temp->father == "00")
            temp->father = to_string(_field->i)+ to_string(_field->j);
        _field->neighbors.add(temp);
    }
    /*! Calcula los vecinos en diagonal */
    if(i > 0 && j > 0){
        temp = &board->operator()(i-1,j-1);
        temp->setInDiagonal(true);
        if(temp->father == "00")
            temp->father = to_string(_field->i)+ to_string(_field->j);
        _field->neighbors.add(temp);
    }if(i < rows-1 && j > 0){
        temp = &board->operator()(i+1,j-1);
        temp->setInDiagonal(true);
        if(temp->father == "00")
            temp->father = to_string(_field->i)+ to_string(_field->j);
        _field->neighbors.add(temp);
    }if(i > 0 && j < cols-1){
        temp = &board->operator()(i-1,j+1);
        temp->setInDiagonal(true);
        if(temp->father == "00")
            temp->father = to_string(_field->i)+ to_string(_field->j);
        _field->neighbors.add(temp);
    }if(i < rows-1 && j < cols-1){
        temp = &board->operator()(i+1,j+1);
        temp->setInDiagonal(true);
        if(temp->father == "00")
            temp->father = to_string(_field->i)+ to_string(_field->j);
        _field->neighbors.add(temp);
    }
}

/*! Calculo del H */
int Pathfinding::heuristic(Field a, Field b) {
    int d  = abs(b.i - a.i) + abs(b.j - a.j);
    //cout<<"Heuristico(H) "<<d<<endl;
    return d;
}

bool Pathfinding::makeRoute() {
    auto timeStart = std::chrono::high_resolution_clock::now();
    openSet.add(*start);
    int winner; /*!< Nodo con el f más bajo */
    int g = 0;

    /*! Mientras el conjunto abierto tenga elementos se ejecuta el algoritmo A* */
    while (openSet.size() > 0) {
        winner = 0;

        //for NO necesario
        /*cout << "Los elementos en la openset son: ";
        for (int g = 0; g < openSet.size(); g++) {
            cout << openSet.getNode(g)->data.i << openSet.getNode(g)->data.j << " ";
        }*/

        /*! Busca en la lista abierta el nodo con el f más bajo*/
        for (int i = 0; i < openSet.size(); i++) {
            if (openSet.getNode(i)->data.f <= openSet.getNode(winner)->data.f) {
                winner = i;
            }
        }

        /*! Es necesario para eliminar los nodos del conjunto abierto*/
        Field temp = openSet.getNode(winner)->data;
        Field *current = &temp;

        //NO necesario
        //cout << endl << "Mi current es " << current->i << current->j << " f=" << current->f << " g=" << current->g<< " h=" << current->h << endl;

        /*! Verifica que el nodo winner sea o no el final
         * IMPORTANTE: Si entra en ese if significa que ya hay una ruta */
        if ((current->i == end->i) && (current->j == end->j)) {
            closeSet.add(*end);
            cout << "Se encontró la mejor ruta!!!" << endl;
            string solution;
            for (int j = 1; j < closeSet.size(); j++) {
                solution += closeSet.getData(j).father + " ";
            }
            solution += to_string(end->i) + to_string(end->j);
            cout << solution << endl;
            auto finish = std::chrono::high_resolution_clock::now();
            cout << "Duración " << chrono::duration_cast<chrono::microseconds>(finish - timeStart).count()
                 << " microsegundos" << endl;
            return true;
        }

        /*! Se remueve de la lista abierta winner*/
        current->deleteField(temp, openSet);
        /*! Pero éste se agrega a la lista cerrada*/
        closeSet.add(*current);
        //cout << "Se agrego un nodo a la lista cerrada " << current->i << current->j << endl;

        /*! Calcular vecinos */
        this->addNeighbors(current);

        /*cout << "Vecinos de current " << current->neighbors.size() << " y son: ";
        for (int i = 0; i < current->neighbors.size(); i++) {
            cout << current->neighbors.getNode(i)->data->i << current->neighbors.getNode(i)->data->j << " ";
        }*/

        /*! Evaluo vecinos*/
        for (int i = 0; i < current->neighbors.size(); i++) {

            //cout << endl << "Vecino numero " << i + 1 << " de " << current->neighbors.size() << endl;
            //cout << "Vecino a evaluar " << current->neighbors.getNode(i)->data->i << " "<< current->neighbors.getNode(i)->data->j << endl;

            /*! Verifica que el vecino a evaluar sea o no el punto final*/
            if (current->neighbors.getData(i)->i == end->i && current->neighbors.getData(i)->j == end->j) {
                closeSet.add(*end);
                cout << "Se encontró la mejor ruta!!!" << endl;
                for (int j = 1; j < closeSet.size(); j++) {
                    solution.add(closeSet.getData(j).father);
                }
                solution.add(to_string(end->i) + to_string(end->j));
                auto finish = std::chrono::high_resolution_clock::now();
                cout << "Duración " << chrono::duration_cast<chrono::microseconds>(finish - timeStart).count()
                     << " microsegundos" << endl;
                return true;
            }

            /*! Verifica que el vecino a evaluar NO este en el conjunto cerrado*/
            bool inCloseSet = false;
            for (int k = 0; k < closeSet.size(); k++) {
                if (closeSet.getData(k).i == current->neighbors.getNode(i)->data->i &&
                    closeSet.getData(k).j == current->neighbors.getNode(i)->data->j)
                    inCloseSet = true;
            }

            /*! Si el vecino no esta en el conjunto cerrado ni es un muro entonces lo evalua*/
            if (!inCloseSet && !current->neighbors.getNode(i)->data->isObstacle()) {
                bool inOpenset = false;
                for (int k = 0; k < openSet.size(); k++) {
                    if (openSet.getData(k).i == current->neighbors.getNode(i)->data->i &&
                        openSet.getData(k).j == current->neighbors.getNode(i)->data->j)
                        inOpenset = true;
                }

                if (inOpenset) {
                        current->neighbors.getData(i)->g = g;
                        current->neighbors.getData(i)->h = this->heuristic(*current->neighbors.getData(i), *end);
                        current->neighbors.getData(i)->f = current->neighbors.getData(i)->g + current->neighbors.getData(i)->h;
                        current->neighbors.getData(i)->father = to_string(current->i) + to_string(current->j);

                }else{
                    current->neighbors.getData(i)->g = g;
                    current->neighbors.getData(i)->h = this->heuristic(*current->neighbors.getData(i), *end);
                    current->neighbors.getData(i)->f = current->neighbors.getData(i)->g + current->neighbors.getData(i)->h;
                    openSet.add(*current->neighbors.getNode(i)->data);
                }
            }
        }
    }
    /*! Si el conjunto abierto ya no tiene elementos por evaluar significa que no se encontró la ruta*/
    cout << "No hay solución" << endl;
    return false;
}
