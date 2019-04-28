#ifndef A_GAME_H
#define A_GAME_H

#include "Matrix.h"
#include "Field.h"
#include "Gladiator.h"
#include "Army.h"
#include "GeneticEvolution.h"

class Game {

    public:
        int rows, columns;
        Matrix<Field> board;
        Army army;
        GeneticEvolution gE;
        int generationCount;


        Game();
        void newGame();
        void play();
};


#endif //A_GAME_H
