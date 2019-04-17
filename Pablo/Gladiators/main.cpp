#include <iostream>
//#include "Army.h"
//#include "List.h"
#include "GeneticEvolution.h"


int main() {
    GeneticEvolution gA;
    gA.army.createArmy(gA.army.armySize);
    gA.army.insertionSort(gA.army.gladiators);
    gA.army.printArray(gA.army.gladiators, gA.army.armySize);
    gA.setFittest();
    cout<<"Fittest: " <<gA.fittest.getResistance()<<endl;
    gA.setSecondFittest();
    cout<<"secondFittest: "<<gA.secondFittest.getResistance()<<endl;

    cout<<"Voy a hacer el crossovereo"<<endl;
    srand(time(NULL));

    gA.crossover();
    gA.generationCount=+1;
    gA.setFittest();
    cout<<"Fittest: " <<gA.fittest.getResistance()<<endl;
    gA.setSecondFittest();
    cout<<"secondFittest: "<<gA.secondFittest.getResistance()<<endl;



    gA.crossover();
    gA.generationCount=+1;
    gA.setFittest();
    cout<<"Fittest: " <<gA.fittest.getResistance()<<endl;
    gA.setSecondFittest();
    cout<<"secondFittest: "<<gA.secondFittest.getResistance()<<endl;


    gA.crossover();
    gA.generationCount=+1;
    gA.setFittest();
    cout<<"Fittest: " <<gA.fittest.getResistance()<<endl;
    gA.setSecondFittest();
    cout<<"secondFittest: "<<gA.secondFittest.getResistance()<<endl;







    return 0;
}