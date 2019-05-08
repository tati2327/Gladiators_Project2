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
        Pathfinding myRoute;
        Gladiator myGladiator;
        List<string> obstaclesList;
        List<Gladiator> historicalArmy;

        Game();
        string newGame();
        string play();
        bool addObstacle();
        void addToHistoricalArmy(List<Gladiator> army);
        string sendGraphic();

        void addResistance(List<Gladiator> historicalArmy);
        void addUpperStrenght(List<Gladiator> historicalArmy);
        void addLowerStrenght(List<Gladiator> historicalArmy);
        void addEmotionalIntelligence(List<Gladiator> historicalArmy);
        void addPhysicalCondition(List<Gladiator> historicalArmy);
        void addAge(List<Gladiator> historicalArmy);
        void addExpectedGenerations(List<Gladiator> historicalArmy);
        void addSurvivalProb(List<Gladiator> historicalArmy);
        void addFitness(List<Gladiator> historicalArmy);
        void addId(List<Gladiator> historicalArmy);

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
};


#endif //A_GAME_H
