#include "Game.h"

Game::Game() {
    this->rows = 10;
    this->columns = 10;
    this->board = Matrix<Field>(rows,columns);
    myRoute = Pathfinding(board);
}

void Game::newGame() {
    /*! Algoritmo genetico*/
    gE.generationCount=+1;
    army.createArmy(army.armySize);
    army.insertionSort(army.gladiators);
    army.printArray(army.gladiators,army.armySize);
    army.setFittest();
    cout<<"Fittest: " <<army.fittest.getResistance()<<endl;
    army.setSecondFittest();
    cout<<"secondFittest: "<<army.secondFittest.getResistance()<<endl;

    /*! Crear el tablero de juego con los obstaculos iniciales*/
    bool end = false;
    while(!end)
        end = this->addObstacles();

}

void Game::play() {
    srand(time(NULL));
    /*!La posibilidad de que se haga la mutacion es un 4%.*/
    int random=(rand() % 99) + 0;
    if(random==45 or random==8 or random==69 or random==27) {
        cout<<"se inicia la muteishon"<<endl;
        gE.mutation(army);
        army.insertionSort(army.gladiators);
        army.printArray(army.gladiators, army.armySize);
        army.setFittest();
        cout << "Fittest: " << army.fittest.getResistance() << endl;
        army.setSecondFittest();
        cout << "secondFittest: " << army.secondFittest.getResistance() << endl;
    }

    /*! Se hace el crossover. */
    cout<<"se inicia el crossovereo"<<endl;
    gE.crossover(army);
    gE.generationCount=+1;
    army.insertionSort(army.gladiators);
    army.printArray(army.gladiators, army.armySize);
    army.setFittest();
    cout<<"Fittest: " <<army.fittest.getResistance()<<endl;
    army.setSecondFittest();
    cout<<"secondFittest: "<<army.secondFittest.getResistance()<<endl;

    /*! Agregar nuevos obstaculos en el tablero*/
    bool end = false;
    while(!end)
        end = this->addObstacles();
}

bool Game::addObstacles() {
    srand(time(NULL));

    int obstacle_i = (rand() % (rows-1)) + 0;
    int obstacle_j = (rand() % (columns-1)) + 0;
    int obstacle2_i = (rand() % (rows-1)) + 0;
    int obstacle2_j = (rand() % (columns-1)) + 0;
    int obstacle3_i = (rand() % (rows-1)) + 0;
    int obstacle3_j = (rand() % (columns-1)) + 0;


    /*! Validar si el obstaculo esta en la entrada o la salida*/
    if((obstacle_i == myRoute.start->i and obstacle_j == myRoute.start->j)
        or (obstacle_i == myRoute.end->i and obstacle_j == myRoute.end->j)){
        cout<<"ERROR el obstaculo esta en la entrada o la salida"<<endl;
        return false;
    }
    if((obstacle2_i == myRoute.start->i and obstacle2_j == myRoute.start->j)
       or (obstacle2_i == myRoute.end->i and obstacle2_j == myRoute.end->j)){
        cout<<"ERROR el obstaculo esta en la entrada o la salida"<<endl;
        return false;
    }
    if((obstacle3_i == myRoute.start->i and obstacle3_j == myRoute.start->j)
       or (obstacle3_i == myRoute.end->i and obstacle3_j == myRoute.end->j)){
        cout<<"ERROR el obstaculo esta en la entrada o la salida"<<endl;
        return false;
    }

    /*! Se agrega el obstaculo*/
    board.operator()(obstacle_i,obstacle_j).addObstacle();
    board.operator()(obstacle2_i,obstacle2_j).addObstacle();
    board.operator()(obstacle3_i,obstacle3_j).addObstacle();

    /*! Se calcula la ruta para saber si hay solucion*/
    myRoute = Pathfinding(board);
    return myRoute.makeRoute();
}



