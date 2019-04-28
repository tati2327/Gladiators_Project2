//
// Created by pablo on 16/04/19.
//

#ifndef GLADIATORS_ARMY_H
#define GLADIATORS_ARMY_H


#include "Gladiator.h"
#include <cstdlib>
#include <ctime>
#include "List.h"
#include <unistd.h>


class Army {
public:
    int armySize;
    Gladiator fittest;
    Gladiator secondFittest;
    List<Gladiator> gladiators;


public:
    Army();
    void printArray(List<Gladiator> gladiators, int n);
    void insertionSort(List<Gladiator> gladiators);
    void createArmy(int armySize);
    Gladiator setRandomValues(Gladiator gladiator,int i);
    Gladiator setHeuristicValues(Gladiator gladiator, int i);
    void setFittest();
    void setSecondFittest();


};


#endif //GLADIATORS_ARMY_H
