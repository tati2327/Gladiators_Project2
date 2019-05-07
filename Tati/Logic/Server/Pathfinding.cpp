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
    start = &board->operator()(rows-1,cols-1);
    end = &board->operator()(0,0);
}

void Pathfinding::addNeighbors(Field *_field) {
    int i = _field->i;
    int j = _field->j;

    Field *temp;
    /*! Calcula los vecinos en vertical y horizontal */
    if(i < rows-1){
        temp = &(board->operator()(i+1,j));
        temp->setInLine(true);
        temp->setInDiagonal(false);
        if(temp->father == "00")
            temp->father = to_string(_field->i)+ to_string(_field->j);
        _field->neighbors.add(temp);
    }if(i>0){
        temp = &board->operator()(i-1,j);
        temp->setInLine(true);
        temp->setInDiagonal(false);
        if(temp->father == "00")
            temp->father = to_string(_field->i)+ to_string(_field->j);
        _field->neighbors.add(temp);
    }if(j < cols-1){
        temp = &board->operator()(i,j+1);
        temp->setInLine(true);
        temp->setInDiagonal(false);
        if(temp->father == "00")
            temp->father = to_string(_field->i)+ to_string(_field->j);
        _field->neighbors.add(temp);
    }if(j > 0){
        temp = &board->operator()(i,j-1);
        temp->setInLine(true);
        temp->setInDiagonal(false);
        if(temp->father == "00")
            temp->father = to_string(_field->i)+ to_string(_field->j);
        _field->neighbors.add(temp);
    }
    /*! Calcula los vecinos en diagonal */
    if(i > 0 && j > 0){
        temp = &board->operator()(i-1,j-1);
        temp->setInDiagonal(true);
        temp->setInLine(false);
        if(temp->father == "00")
            temp->father = to_string(_field->i)+ to_string(_field->j);
        _field->neighbors.add(temp);
    }if(i < rows-1 && j > 0){
        temp = &board->operator()(i+1,j-1);
        temp->setInDiagonal(true);
        temp->setInLine(false);
        if(temp->father == "00")
            temp->father = to_string(_field->i)+ to_string(_field->j);
        _field->neighbors.add(temp);
    }if(i > 0 && j < cols-1){
        temp = &board->operator()(i-1,j+1);
        temp->setInDiagonal(true);
        temp->setInLine(false);
        if(temp->father == "00")
            temp->father = to_string(_field->i)+ to_string(_field->j);
        _field->neighbors.add(temp);
    }if(i < rows-1 && j < cols-1){
        temp = &board->operator()(i+1,j+1);
        temp->setInDiagonal(true);
        temp->setInLine(false);
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

    //cout<<"La PS tiene "<<openSet.size()<<" elementos"<<endl;
    //cout<<"La CS tiene "<<closeSet.size()<<" elementos"<<endl;


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
            end->father = to_string(current->i)+to_string(current->j);
            closeSet.add(*end);
            cout << "Se encontró la mejor ruta!!!" << endl;
            string tempFather;
            string tempCompare;
            List<string> tempSolution;

            tempSolution.add(to_string(end->i) + to_string(end->j));
            tempSolution.add(closeSet.getData(closeSet.size()-1).father);
            tempFather = closeSet.getData(closeSet.size()-1).father;

            for (int j = (closeSet.size()-2); j >=0; j--) {
                if(tempFather == "00")
                    break;
                //cout<<"tempFather es "<<tempFather<<endl;
                tempCompare = to_string(closeSet.getData(j).i) + to_string(closeSet.getData(j).j);
                if(tempCompare == tempFather){
                    tempSolution.add(closeSet.getData(j).father);
                    tempFather = closeSet.getData(j).father;
                }
                //cout<<closeSet.getData(j).i<<closeSet.getData(j).j<<" "<<closeSet.getData(j).father<<endl;
            }

            for(int j=0; j<(tempSolution.size()-1); j++)
                solution.add(tempSolution.getData(j));

            auto finish = std::chrono::high_resolution_clock::now();
            cout << "Duración " << chrono::duration_cast<chrono::microseconds>(finish - timeStart).count()<< " microsegundos" << endl;
            this->cleanAll();
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
            cout << current->neighbors.getNode(i)->data->i << current->neighbors.getNode(i)->data->j << " con F "<< current->neighbors.getNode(i)->data->f<<" -- ";
        }*/

        /*! Evaluo vecinos*/
        for (int i = 0; i < current->neighbors.size(); i++) {

            /*cout << endl << "Vecino numero " << i + 1 << " de " << current->neighbors.size() << endl;
            cout << "Vecino a evaluar " << current->neighbors.getNode(i)->data->i << " "<< current->neighbors.getNode(i)->data->j << endl;
            cout<<" g "<<current->neighbors.getNode(i)->data->g<<" y esta en diagonal? "<<current->neighbors.getNode(i)->data->inDiagonal<<endl;*/

            /*! Verifica que el vecino a evaluar sea o no el punto final*/
            if (current->neighbors.getData(i)->i == end->i && current->neighbors.getData(i)->j == end->j) {
                end->father = to_string(current->i)+to_string(current->j);
                closeSet.add(*end);
                cout << "Se encontró la mejor ruta!!!" << endl;
                string tempFather;
                string tempCompare;
                List<string> tempSolution;

                tempSolution.add(to_string(end->i) + to_string(end->j));
                tempSolution.add(closeSet.getData(closeSet.size()-1).father);
                tempFather = closeSet.getData(closeSet.size()-1).father;

                for (int j = (closeSet.size()-2); j >=0; j--) {
                    if(tempFather == "00")
                        break;
                    //cout<<"tempFather es "<<tempFather<<endl;
                    tempCompare = to_string(closeSet.getData(j).i) + to_string(closeSet.getData(j).j);
                    if(tempCompare == tempFather){
                        tempSolution.add(closeSet.getData(j).father);
                        tempFather = closeSet.getData(j).father;
                    }
                    //cout<<closeSet.getData(j).i<<closeSet.getData(j).j<<" "<<closeSet.getData(j).father<<endl;
                }

                for(int j=0; j<(tempSolution.size()-1); j++)
                    solution.add(tempSolution.getData(j));

                auto finish = std::chrono::high_resolution_clock::now();
                cout << "Duración " << chrono::duration_cast<chrono::microseconds>(finish - timeStart).count()<< " microsegundos" << endl;
                this->cleanAll();
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
            if (!inCloseSet && !current->neighbors.getNode(i)->data->isObstacle()){
                if(!(current->neighbors.getData(i)->i == start->i && current->neighbors.getData(i)->j == start->j)){
                    bool inOpenset = false;
                    for (int k = 0; k < openSet.size(); k++) {
                        if (openSet.getData(k).i == current->neighbors.getNode(i)->data->i &&
                            openSet.getData(k).j == current->neighbors.getNode(i)->data->j)
                            inOpenset = true;
                    }

                    if(current->neighbors.getData(i)->inLine) g=10;
                    else g=14;

                    if(inOpenset) {
                        //cout<<"Ya esta en la lista abierta"<<endl;
                        if((current->g + g) < current->neighbors.getData(i)->g) {
                            current->neighbors.getData(i)->g = current->g + g;
                            current->neighbors.getData(i)->h = this->heuristic(*current->neighbors.getData(i), *end);
                            current->neighbors.getData(i)->f = current->neighbors.getData(i)->g + current->neighbors.getData(i)->h;
                            current->neighbors.getData(i)->father = to_string(current->i) + to_string(current->j);
                            //cout<<"Se le cambio el padre y su padre ahora es "<<to_string(current->i) + to_string(current->j)<<endl;

                        }
                    }else{
                        current->neighbors.getData(i)->g = current->g + g;
                        current->neighbors.getData(i)->h = this->heuristic(*current->neighbors.getData(i), *end);
                        current->neighbors.getData(i)->f = current->neighbors.getData(i)->g + current->neighbors.getData(i)->h;
                        openSet.add(*current->neighbors.getNode(i)->data);
                        current->neighbors.getData(i)->father = to_string(current->i) + to_string(current->j);
                        //cout<<"Su padre ahora es "<<to_string(current->i) + to_string(current->j)<<endl;
                    }
                    //cout<<" g "<<current->neighbors.getNode(i)->data->g<<endl;
                    //cout<<" f "<<current->neighbors.getNode(i)->data->f<<endl;
                }
            }
        }
    }
    /*! Si el conjunto abierto ya no tiene elementos por evaluar significa que no se encontró la ruta*/
    cout << "No hay solución" << endl;
    return false;
}

void Pathfinding::cleanAll() {
    for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
            board->operator()(i,j).father = "00";
            board->operator()(i,j).h = 0;
            board->operator()(i,j).g = 0;
            board->operator()(i,j).f = 0;
        }
    }

}
