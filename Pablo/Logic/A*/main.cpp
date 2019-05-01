#include <iostream>
#include "Field.h"
#include "Pathfinding.h"
#include "Matrix.h"
#include "GeneticEvolution.h"
#include "Game.h"

int main() {

    /*Matrix<Field> m = Matrix<Field >(10,10);

    Pathfinding p = Pathfinding(m);

    m.operator()(0,1).addObstacle();
    m.operator()(2,1).addObstacle();
    m.operator()(3,2).addObstacle();
    m.operator()(1,3).addObstacle();

    p.makeRoute();*/

    Army army;
    GeneticEvolution gA;

    //Primera generacion.
    gA.generationCount=+1;

    srand(time(NULL));

    army.createArmy(army.armySize);
    army.insertionSort(army.gladiators);
    army.printArray(army.gladiators,army.armySize);

    int i = 0;
    while (i!=10) {
        //Se hace el crossover.
        cout << "Se inicia el crossovereo" << endl;
        gA.crossover(army,19,18,0);
        gA.crossover(army,19,17,1);

        gA.crossover(army,19,16,2);

        gA.crossover(army,18,17,3);

        gA.crossover(army,18,16,4);



        gA.generationCount=+1;
        i++;
        cout<< "/////////////////////////////////////////////////////////////////////////////////////"<< endl;
    }

    return 0;
}