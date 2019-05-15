#include <iostream>
#include "Field.h"
#include "Pathfinding.h"
#include "Matrix.h"
#include "GeneticEvolution.h"
#include "Game.h"
#include "Server.h"

int main() {

    srand(time(NULL));
    /*Game myGame;
    myGame.newGame();
    myGame.play();*/

    //Server s;
    //s.initServer();
    GeneticEvolution gE;
    /*Army army;
    srand(time(NULL));
    army.createArmy(army.armySize);
    army.insertionSort(army.gladiators);
    army.printArray(army.gladiators, army.armySize);
    gE.updateAge(army);


    int i=0;
    while(i!=30){
        gE.updateAge(army);
        gE.crossover(army,19,18);
        gE.crossover(army,19,18);
        gE.crossover(army,19,18);
        gE.crossover(army,19,17);
        gE.crossover(army,17,19);
        gE.crossover(army,18,17);
        gE.crossover(army,17,18);
        gE.crossover(army,18,16);

        gE.addNewGladiators(gE.newGladiators,army);
        gE.newGladiators.cleanList();
        army.insertionSort(army.gladiators);
        army.printArray(army.gladiators, army.armySize);
        i++;
    }*/




    return 0;
}