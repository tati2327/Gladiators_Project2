#include <iostream>
#include "Field.h"
#include "Pathfinding.h"
#include "Matrix.h"
#include "GeneticEvolution.h"
#include "Game.h"
#include "Server.h"

int main() {

    srand(time(NULL));
    Game myGame;
    myGame.newGame();
    myGame.play();

    //Server s;
    //s.initServer();

    return 0;
}