#include <iostream>
#include "Field.h"
#include "Pathfinding.h"
#include "Matrix.h"
#include "GeneticEvolution.h"

int main() {

    /*Matrix<Field> m = Matrix<Field >(10,10);

    Pathfinding p = Pathfinding(m);

    m.operator()(0,1).addObstacle();
    m.operator()(2,1).addObstacle();
    m.operator()(3,2).addObstacle();
    m.operator()(1,3).addObstacle();

    p.makeRoute();*/

    GeneticEvolution gA;

    //Primera generacion.
    gA.generationCount=+1;
    gA.army.createArmy(gA.army.armySize);
    gA.army.insertionSort(gA.army.gladiators);
    gA.army.printArray(gA.army.gladiators, gA.army.armySize);
    gA.setFittest();
    cout<<"Fittest: " <<gA.fittest.getResistance()<<endl;
    gA.setSecondFittest();
    cout<<"secondFittest: "<<gA.secondFittest.getResistance()<<endl;

    srand(time(NULL));

    //La posibilidad de que se haga la mutacion es un 1%.
    //int random=(rand() % 99) + 0;
    //if(random==45) {
    cout<<"se inicia la muteishon"<<endl;
    gA.mutation();
    gA.army.insertionSort(gA.army.gladiators);
    gA.army.printArray(gA.army.gladiators, gA.army.armySize);
    gA.setFittest();
    cout << "Fittest: " << gA.fittest.getResistance() << endl;
    gA.setSecondFittest();
    cout << "secondFittest: " << gA.secondFittest.getResistance() << endl;
    //}


    //Se hace el crossover.
    cout<<"se inicia el crossovereo"<<endl;
    gA.crossover();
    gA.generationCount=+1;
    gA.army.insertionSort(gA.army.gladiators);
    gA.army.printArray(gA.army.gladiators, gA.army.armySize);
    gA.setFittest();
    cout<<"Fittest: " <<gA.fittest.getResistance()<<endl;
    gA.setSecondFittest();
    cout<<"secondFittest: "<<gA.secondFittest.getResistance()<<endl;
    //Segunda Generacion

    return 0;
}