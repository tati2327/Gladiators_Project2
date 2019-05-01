#include <iostream>
#include "Army.h"
#include "List.h"
#include "GeneticEvolution.h"


int main() {
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
    int i=0;
    while(i!=20) {
        srand(time(NULL));

        /*//La posibilidad de que se haga la mutacion es un 1%.
        //int random=(rand() % 99) + 0;
        //if(random==45) {
        cout << "se inicia la muteishon" << endl;
        gA.mutation();
        gA.army.insertionSort(gA.army.gladiators);
        gA.army.printArray(gA.army.gladiators, gA.army.armySize);
        gA.setFittest();
        cout << "Fittest: " << gA.fittest.getResistance() << endl;
        gA.setSecondFittest();
        cout << "secondFittest: " << gA.secondFittest.getResistance() << endl;
        //}*/


        //Se hace el crossover.
        cout << "se inicia el crossovereo" << endl;
        gA.crossover();
        gA.generationCount = +1;
        gA.army.insertionSort(gA.army.gladiators);
        gA.army.printArray(gA.army.gladiators, gA.army.armySize);
        gA.setFittest();
        cout << "Fittest: " << gA.fittest.getResistance() << endl;
        gA.setSecondFittest();
        cout << "secondFittest: " << gA.secondFittest.getResistance() << endl;
        //Segunda Generacion
        cout<<"///////////////////////////////////////////////////"<<endl;
        i++;
    }

    return 0;
}