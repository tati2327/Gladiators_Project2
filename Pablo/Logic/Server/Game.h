#ifndef A_GAME_H
#define A_GAME_H

#include "Matrix.h"
#include "Field.h"
#include "Gladiator.h"
#include "Army.h"
#include "GeneticEvolution.h"
#include "Pathfinding.h"
#include "JSON.h"

class Game {

    public:
        int rows, columns;
        Matrix<Field> board;
        Army army;
        GeneticEvolution gE;
        int generationCount;
        Pathfinding myRoute;
        Gladiator myGladiator;
        List<string> obstaclesList;
        List<Gladiator> historicalArmy;
        List<int> resistance;
        List<int> upperStrenght;
        List<int> lowerStrenght;
        List<int> emotionalIntelligence;
        List<int> physicalCondition;
        List<int> age;
        List<int> expectedGenerations;
        List<int> survivalProb;
        List<int> fitness;
        List<int> id;




    Game();
        string newGame();
        string play();
        bool addObstacle1();
        bool addObstacle2();
        bool addObstacle3();
        void addToHistoricalArmy(List<Gladiator> army);
        List<int> addResistance(List<Gladiator> historicalArmy);
        List<int> addUpperStrenght(List<Gladiator> historicalArmy);
        List<int> addLowerStrenght(List<Gladiator> historicalArmy);
        List<int> addEmotionalIntelligence(List<Gladiator> historicalArmy);
        List<int> addPhysicalCondition(List<Gladiator> historicalArmy);
        List<int> addAge(List<Gladiator> historicalArmy);
        List<int> addExpectedGenerations(List<Gladiator> historicalArmy);
        List<int> addSurvivalProb(List<Gladiator> historicalArmy);
        List<int> addFitness(List<Gladiator> historicalArmy);
        List<int> addId(List<Gladiator> historicalArmy);

};


#endif //A_GAME_H
