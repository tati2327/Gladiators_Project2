#include "Game.h"

Game::Game() {
    this->generationCount=0;
    this->rows = 10;
    this->columns = 10;
    this->board = Matrix<Field>(rows,columns);
    myRoute = Pathfinding(board);
}

void Game::newGame() {
    /*! Algoritmo genetico*/


    /*! Crear el tablero de juego con los obstaculos iniciales*/
    bool end = false;
    while(!end)
        end = this->addObstacles();
}

void Game::play() {


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



