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

        Game();
        string newGame();
        string play();
        bool addObstacle1();
        bool addObstacle2();
        bool addObstacle3();

};


#endif //A_GAME_H
