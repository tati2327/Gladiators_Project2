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

    /*Army army;
    GeneticEvolution gA;

    //Primera generacion.
    gA.generationCount=+1;
    army.createArmy(army.armySize);
    army.insertionSort(army.gladiators);
    army.printArray(army.gladiators,army.armySize);
    army.setFittest();
    cout<<"Fittest: " <<army.fittest.getResistance()<<endl;
    army.setSecondFittest();
    cout<<"secondFittest: "<<army.secondFittest.getResistance()<<endl;

    srand(time(NULL));

    //La posibilidad de que se haga la mutacion es un 4%.
    int random=(rand() % 99) + 0;
    if(random==45 or random==8 or random==69 or random==27) {
        cout<<"se inicia la muteishon"<<endl;
        gA.mutation(army);
        army.insertionSort(army.gladiators);
        army.printArray(army.gladiators, army.armySize);
        army.setFittest();
        cout << "Fittest: " << army.fittest.getResistance() << endl;
        army.setSecondFittest();
        cout << "secondFittest: " << army.secondFittest.getResistance() << endl;
    }


    //Se hace el crossover.
    cout<<"se inicia el crossovereo"<<endl;
    gA.crossover(army);
    gA.generationCount=+1;
    army.insertionSort(army.gladiators);
    army.printArray(army.gladiators, army.armySize);
    army.setFittest();
    cout<<"Fittest: " <<army.fittest.getResistance()<<endl;
    army.setSecondFittest();
    cout<<"secondFittest: "<<army.secondFittest.getResistance()<<endl;
    //Segunda Generacion*/

    Game myGame;
    myGame.newGame();

    return 0;
}