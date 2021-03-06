#include "Game.h"
#include "JSON.h"
#include <document.h>
#include "Gladiator.h"

using namespace rapidjson;

Game::Game() {
    this->rows = 10;
    this->columns = 10;
    this->board = Matrix<Field>(rows,columns);
    error = 0;
    myRoute = Pathfinding(board);
}

string Game::newGame() {
    /*! Algoritmo genetico*/
    gE.generationCount+=1;
    army.createArmy(army.armySize);
    army.insertionSort(army.gladiators);
    army.printArray(army.gladiators, army.armySize);


    myGladiator = army.getFittest();
    addToHistoricalArmy(army.gladiators);
    /*! Agrega obstaculos iniciales en el tablero y calcula la ruta*/
    bool end = false;
    if(error < 10) {
        error = 0;
        while (!end) {
                if (error>10){
                    myRoute = Pathfinding(board);
                    break;
                }
                while (!end) end = this->addObstacle();
                end = false;
                cout << "Se agrego el obstaculo 1" << endl;
                while (!end) end = this->addObstacle();
                end = false;
                cout << "Se agrego el obstaculo 2" << endl;
                while (!end) end = this->addObstacle();
                end = false;
                cout << "Se agrego el obstaculo 3" << endl;

                myRoute = Pathfinding(board);
                if (myRoute.makeRoute())
                    end = true;

                if (!end) {
                    board.operator()(obstaclesList.getData(0)[0] - '0',
                                     obstaclesList.getData(0)[1] - '0').obstacle = false;
                    board.operator()(obstaclesList.getData(1)[0] - '0',
                                     obstaclesList.getData(1)[1] - '0').obstacle = false;
                    board.operator()(obstaclesList.getData(2)[0] - '0',
                                     obstaclesList.getData(2)[1] - '0').obstacle = false;
                    obstaclesList.cleanList();
                }
                error++;
            }
        }

    /*! Convertir los datos a json para que el servidor los envie al cliente*/
    JSON j;
    string json = j.serializePlay(myGladiator.getId(), myGladiator.getAge(), myGladiator.getSurvivalProb(),
                               myGladiator.getExpectedGenerations(),
                               myGladiator.getEmotionalInt(), myGladiator.getUpperTrunckStrenght(),
                               myGladiator.getLowerTrunckStrenght(),
                               myGladiator.getResistance(), myGladiator.getPhysicalCondition(), obstaclesList,
                               this->myRoute.solution, myRoute.time, gE.generationCount);
    obstaclesList.cleanList();
    myRoute.time = 0;
    return json;
}

string Game::play() {
    gE.updateAge(army);
    gE.crossover(army,19,18);
    gE.crossover(army,18,19);
    gE.crossover(army,19,18);
    gE.crossover(army,19,17);
    gE.crossover(army,19,16);
    gE.crossover(army,18,17);
    gE.crossover(army,18,16);
    gE.addNewGladiators(gE.newGladiators,army);
    gE.newGladiators.cleanList();
    army.insertionSort(army.gladiators);
    army.printArray(army.gladiators,army.armySize);

    gE.generationCount+=1;
    myGladiator = army.getFittest();
    addToHistoricalArmy(army.gladiators);

    /*! Agregar nuevos obstaculos en el tablero y calcular la ruta*/
    bool end = false;
    while(!end) {
        if (error>10){
            myRoute = Pathfinding(board);
            break;
        }
        while(!end) end = this->addObstacle(); end=false;
        cout<<"Se agrego el obstaculo 1"<<endl;
        while(!end) end = this->addObstacle(); end=false;
        cout<<"Se agrego el obstaculo 2"<<endl;
        while(!end) end = this->addObstacle(); end=false;
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
        error++;
    }

    /*! Convertir los datos a json para que el servidor los envie al cliente*/
    JSON j;
    string json = j.serializePlay(myGladiator.getId(), myGladiator.getAge(), myGladiator.getSurvivalProb(),
                                  myGladiator.getExpectedGenerations(),
                                  myGladiator.getEmotionalInt(), myGladiator.getUpperTrunckStrenght(),
                                  myGladiator.getLowerTrunckStrenght(),
                                  myGladiator.getResistance(), myGladiator.getPhysicalCondition(), obstaclesList,
                                  this->myRoute.solution, myRoute.time, gE.generationCount);
    obstaclesList.cleanList();
    myRoute.time = 0;
    return json;
}

bool Game::addObstacle() {
    int obstacle_i = (rand() % (rows)) + 0;
    int obstacle_j = (rand() % (columns)) + 0;
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

void Game::addToHistoricalArmy(List<Gladiator> army) {
    for(int i=0;i<=19;i++){
        historicalArmy.add(army.getData(i));
    }
}

void Game::addResistance(List<Gladiator> historicalArmy) {
    int size=historicalArmy.size();
    for(int i=0;i<=size-1;i++){
        resistance.add(historicalArmy.getData(i).getResistance());
    }
}

void Game::addUpperStrenght(List<Gladiator> historicalArmy) {
    int size=historicalArmy.size();
    for(int i=0;i<=size-1;i++){
        upperStrenght.add(historicalArmy.getData(i).getUpperTrunckStrenght());
    }
}

void Game::addLowerStrenght(List<Gladiator> historicalArmy) {
    int size=historicalArmy.size();
    for(int i=0;i<=size-1;i++){
        lowerStrenght.add(historicalArmy.getData(i).getResistance());
    }
}

void Game::addEmotionalIntelligence(List<Gladiator> historicalArmy) {
    int size=historicalArmy.size();
    for(int i=0;i<=size-1;i++){
        emotionalIntelligence.add(historicalArmy.getData(i).getEmotionalInt());
    }
}

void Game::addPhysicalCondition(List<Gladiator> historicalArmy) {
    int size=historicalArmy.size();
    for(int i=0;i<=size-1;i++){
        physicalCondition.add(historicalArmy.getData(i).getPhysicalCondition());
    }
}

void Game::addAge(List<Gladiator> historicalArmy) {
    int size=historicalArmy.size();
    for(int i=0;i<=size-1;i++){
        age.add(historicalArmy.getData(i).getAge());
    }
}

void Game::addExpectedGenerations(List<Gladiator> historicalArmy) {
    int size=historicalArmy.size();
    for(int i=0;i<=size-1;i++){
        expectedGenerations.add(historicalArmy.getData(i).getExpectedGenerations());
    }
}

void Game::addSurvivalProb(List<Gladiator> historicalArmy) {
    int size=historicalArmy.size();
    for(int i=0;i<=size-1;i++){
        survivalProb.add(historicalArmy.getData(i).getSurvivalProb());
    }
}

void Game::addFitness(List<Gladiator> historicalArmy) {
    int size=historicalArmy.size();
    for(int i=0;i<=size-1;i++){
        fitness.add(historicalArmy.getData(i).getFitness());
    }
}

void Game::addId(List<Gladiator> historicalArmy) {
    int size=historicalArmy.size();
    for(int i=0;i<=size-1;i++){
        id.add(historicalArmy.getData(i).getId());
    }
}

string Game::sendGraphic() {
    addResistance(historicalArmy);
    addUpperStrenght(historicalArmy);
    addLowerStrenght(historicalArmy);
    addEmotionalIntelligence(historicalArmy);
    addPhysicalCondition(historicalArmy);
    addAge(historicalArmy);
    addSurvivalProb(historicalArmy);
    addExpectedGenerations(historicalArmy);
    addFitness(historicalArmy);
    addId(historicalArmy);

    JSON j;
    string json = j.serializeGraphic(resistance,upperStrenght,lowerStrenght,
            emotionalIntelligence,physicalCondition,age,expectedGenerations,
            survivalProb,fitness,id);
    return json;
}
