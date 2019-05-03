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
    gE.generationCount=+1;
    army.createArmy(army.armySize);
    army.insertionSort(army.gladiators);
    army.printArray(army.gladiators,army.armySize);
    army.setFittest();
    cout<<"Fittest: " <<army.fittest.getResistance()<<endl;
    army.setSecondFittest();
    cout<<"secondFittest: "<<army.secondFittest.getResistance()<<endl;
    myGladiator = army.fittest;

    /*! Crear el tablero de juego con los obstaculos iniciales*/
    string end = "false";
    List<string> message;
    while(end == "false") {
        message = this->addObstacles();
        end = message[0];
    }
    message.deleteNode("true");

    /*! Convertir los datos a json para que el servidor los envie al cliente*/
    JSON j;
    string json = j.serializePlay(myGladiator.getId(), myGladiator.getAge(), myGladiator.getSurvivalProb(),
                               myGladiator.getExpectedGenerations(),
                               myGladiator.getEmotionalInt(), myGladiator.getUpperTrunckStrenght(),
                               myGladiator.getLowerTrunckStrenght(),
                               myGladiator.getResistance(), myGladiator.getPhysicalCondition(), message, this->sendRoute());
    return json;
}

string Game::play() {
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
    myGladiator = army.fittest;

    /*! Agregar nuevos obstaculos en el tablero*/
    string end = "false";
    List<string> message;
    while(end == "false") {
        message = this->addObstacles();
        end = message[0];
    }
    message.deleteNode("true");

    /*! Convertir los datos a json para que el servidor los envie al cliente*/
    JSON j;
    string json = j.serializePlay(myGladiator.getId(), myGladiator.getAge(), myGladiator.getSurvivalProb(),
                                  myGladiator.getExpectedGenerations(),
                                  myGladiator.getEmotionalInt(), myGladiator.getUpperTrunckStrenght(),
                                  myGladiator.getLowerTrunckStrenght(),
                                  myGladiator.getResistance(), myGladiator.getPhysicalCondition(), message, this->sendRoute());
    return json;
}

List<string> Game::addObstacles() {
    srand(time(NULL));
    List<string> answer;

    int obstacle_i = (rand() % (rows-1)) + 0;
    int obstacle_j = (rand() % (columns-1)) + 0;
    int obstacle2_i = (rand() % (rows-1)) + 0;
    int obstacle2_j = (rand() % (columns-1)) + 0;
    int obstacle3_i = (rand() % (rows-1)) + 0;
    int obstacle3_j = (rand() % (columns-1)) + 0;


    /*! Validar si el obstaculo esta en la entrada o la salida*/
    if((obstacle_i == myRoute.start->i and obstacle_j == myRoute.start->j)
        or (obstacle_i == myRoute.end->i and obstacle_j == myRoute.end->j)){
        cout<<"ERROR el obstaculo esta en la entrada o la salida "<<obstacle_i<<obstacle_j<<endl;
        answer.add("false");
        return answer;
    }
    if((obstacle2_i == myRoute.start->i and obstacle2_j == myRoute.start->j)
       or (obstacle2_i == myRoute.end->i and obstacle2_j == myRoute.end->j)){
        cout<<"ERROR el obstaculo esta en la entrada o la salida "<<obstacle2_i<<obstacle2_j<<endl;
        answer.add("false");
        return answer;
    }
    if((obstacle3_i == myRoute.start->i and obstacle3_j == myRoute.start->j)
       or (obstacle3_i == myRoute.end->i and obstacle3_j == myRoute.end->j)){
        cout<<"ERROR el obstaculo esta en la entrada o la salida "<<obstacle3_i<<obstacle3_j<<endl;
        answer.add("false");
        return answer;
    }

    /*! Se agrega el obstaculo*/
    board.operator()(obstacle_i,obstacle_j).addObstacle();
    board.operator()(obstacle2_i,obstacle2_j).addObstacle();
    board.operator()(obstacle3_i,obstacle3_j).addObstacle();

    /*! Se calcula la ruta para saber si hay solucion*/
    myRoute = Pathfinding(board);

    if(myRoute.makeRoute()) {
        answer.add("true");
        answer.add(to_string(obstacle_i)+to_string(obstacle_j));
        answer.add(to_string(obstacle2_i)+to_string(obstacle2_j));
        answer.add(to_string(obstacle3_i)+to_string(obstacle3_j));
        return answer;
    }
    answer.add("false");
    return answer;
}

List<Field> Game::sendRoute() {
    return myRoute.closeSet;
}



