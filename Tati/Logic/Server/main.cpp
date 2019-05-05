#include <iostream>
#include "Field.h"
#include "Pathfinding.h"
#include "Matrix.h"
#include "GeneticEvolution.h"
#include "Game.h"
#include "Server.h"

int main() {

    /*Matrix<Field> m = Matrix<Field>(10,10);
    Pathfinding p = Pathfinding(m);
    p.makeRoute();*/

    Game myGame;
    myGame.newGame();
    //Server s;
    //s.initServer();

    return 0;
}