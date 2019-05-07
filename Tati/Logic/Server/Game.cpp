#include "Game.h"
#include "JSON.h"
#include <document.h>

using namespace rapidjson;

Game::Game() {
    this->rows = 10;
    this->columns = 10;
    this->board = Matrix<Field>(rows,columns);
    myRoute = Pathfinding(board);
}

string Game::newGame() {
    /*! Algoritmo genetico*/
    gE.generationCount = +1;
    army.createArmy(army.armySize);
    army.insertionSort(army.gladiators);
    army.printArray(army.gladiators, army.armySize);
    myGladiator = army.getFittest();

    /*! Agregar nuevos obstaculos en el tablero*/
    bool end = false;
    while(!end) {
        while(!end) end = this->addObstacle2(); end=false;
        cout<<"Se agrego el obstaculo 1"<<endl;
        while(!end) end = this->addObstacle2(); end=false;
        cout<<"Se agrego el obstaculo 2"<<endl;
        while(!end) end = this->addObstacle3(); end=false;
        cout<<"Se agrego el obstaculo 3"<<endl;

        myRoute = Pathfinding(board);
        if(myRoute.makeRoute())
            end = true;

        if(!end){
            board.operator()(obstaclesList.getData(0)[0]-'0',obstaclesList.getData(0)[1]-'0').obstacle=false;
            board.operator()(obstaclesList.getData(1)[0]-'0',obstaclesList.getData(1)[1]-'0').obstacle=false;
            board.operator()(obstaclesList.getData(2)[0]-'0',obstaclesList.getData(2)[1]-'0').obstacle=false;
            obstaclesList.cleanList();
        }
    }

    /*! Convertir los datos a json para que el servidor los envie al cliente*/
    JSON j;
    string json = j.serializePlay(myGladiator.getId(), myGladiator.getAge(), myGladiator.getSurvivalProb(),
                               myGladiator.getExpectedGenerations(),
                               myGladiator.getEmotionalInt(), myGladiator.getUpperTrunckStrenght(),
                               myGladiator.getLowerTrunckStrenght(),
                               myGladiator.getResistance(), myGladiator.getPhysicalCondition(), obstaclesList, this->myRoute.solution);
    obstaclesList.cleanList();
    return json;
}

string Game::play() {
    gE.crossover(army,19,18,0);
    gE.crossover(army,19,17,1);
    gE.crossover(army,19,16,2);
    gE.crossover(army,18,17,3);
    gE.crossover(army,18,16,4);

    gE.generationCount=+1;
    myGladiator = army.getFittest();

    /*! Agregar nuevos obstaculos en el tablero*/
    bool end = false;
    while(!end) {
        while(!end) end = this->addObstacle2(); end=false;
        cout<<"Se agrego el obstaculo 1"<<endl;
        while(!end) end = this->addObstacle2(); end=false;
        cout<<"Se agrego el obstaculo 2"<<endl;
        while(!end) end = this->addObstacle3(); end=false;
        cout<<"Se agrego el obstaculo 3"<<endl;

        myRoute = Pathfinding(board);
        if(myRoute.makeRoute())
            end = true;

        if(!end){
            board.operator()(obstaclesList.getData(0)[0]-'0',obstaclesList.getData(0)[1]-'0').obstacle=false;
            board.operator()(obstaclesList.getData(1)[0]-'0',obstaclesList.getData(1)[1]-'0').obstacle=false;
            board.operator()(obstaclesList.getData(2)[0]-'0',obstaclesList.getData(2)[1]-'0').obstacle=false;
            obstaclesList.cleanList();
        }
    }

    /*! Convertir los datos a json para que el servidor los envie al cliente*/
    JSON j;
    string json = j.serializePlay(myGladiator.getId(), myGladiator.getAge(), myGladiator.getSurvivalProb(),
                                  myGladiator.getExpectedGenerations(),
                                  myGladiator.getEmotionalInt(), myGladiator.getUpperTrunckStrenght(),
                                  myGladiator.getLowerTrunckStrenght(),
                                  myGladiator.getResistance(), myGladiator.getPhysicalCondition(), obstaclesList, this->myRoute.solution);
    obstaclesList.cleanList();
    return json;
}

bool Game::addObstacle1() {
    int obstacle_i = (rand() % (rows-1)) + 0;
    int obstacle_j = (rand() % (columns-1)) + 0;

    string obstacle1 = to_string(obstacle_i)+to_string(obstacle_j);
    string end = to_string(myRoute.end->i)+to_string(myRoute.end->j);

    /*! Validar si el obstaculo esta en la entrada o la salida*/
    if(obstacle1 == "00" or obstacle1 == end){
        cout<<"ERROR el obstaculo 1 esta en la entrada o la salida "<<obstacle_i<<obstacle_j<<endl;
        return false;
    }
    if(board.operator()(obstacle_i,obstacle_j).obstacle){
        cout<<"Error"<<endl;
        return false;
    }

    board.operator()(obstacle_i,obstacle_j).addObstacle();
    obstaclesList.add(obstacle1);
    return true;
}

bool Game::addObstacle2() {
    int obstacle_i = (rand() % (rows-1)) + 0;
    int obstacle_j = (rand() % (columns-1)) + 0;

    string obstacle1 = to_string(obstacle_i)+to_string(obstacle_j);
    string end = to_string(myRoute.end->i)+to_string(myRoute.end->j);

    /*! Validar si el obstaculo esta en la entrada o la salida*/
    if(obstacle1 == "00" or obstacle1 == end){
        cout<<"ERROR el obstaculo 1 esta en la entrada o la salida "<<obstacle_i<<obstacle_j<<endl;
        return false;
    }
    if(board.operator()(obstacle_i,obstacle_j).obstacle){
        cout<<"Error"<<endl;
        return false;
    }

    board.operator()(obstacle_i,obstacle_j).addObstacle();
    obstaclesList.add(obstacle1);
    return true;
}

bool Game::addObstacle3() {
    int obstacle_i = (rand() % (rows-1)) + 0;
    int obstacle_j = (rand() % (columns-1)) + 0;

    string obstacle1 = to_string(obstacle_i)+to_string(obstacle_j);
    string end = to_string(myRoute.end->i)+to_string(myRoute.end->j);

    /*! Validar si el obstaculo esta en la entrada o la salida*/
    if(obstacle1 == "00" or obstacle1 == end){
        cout<<"ERROR el obstaculo 1 esta en la entrada o la salida "<<obstacle_i<<obstacle_j<<endl;
        return false;
    }
    if(board.operator()(obstacle_i,obstacle_j).obstacle){
        cout<<"Error"<<endl;
        return false;
    }

    board.operator()(obstacle_i,obstacle_j).addObstacle();
    obstaclesList.add(obstacle1);
    return true;
}



