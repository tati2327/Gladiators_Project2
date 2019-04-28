#ifndef A_GAME_H
#define A_GAME_H

#include "Matrix.h"
#include "Field.h"
#include "Gladiator.h"

class Game {

    public:
        int rows, columns;
        Matrix<Field> board;
        Gladiator fittest;
        Gladiator secondFittest;
        int generationCount;


        Game();
        void newGame();
        void play();
        void updatePosGladiator(int i, int j);
        void createInitialArmy();
        

};


#endif //A_GAME_H
