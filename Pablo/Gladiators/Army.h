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
    List<Gladiator*> gladiators;


public:
    Army(int armySize);
    void printArray(int *array, int n);
    void insertionSort(List<Gladiator*> gladiators, int listSize);
    void createArmy(int armySize);
    Gladiator* setRandomValues(Gladiator *gladiator,int i);
    Gladiator* setHeuristicValues(Gladiator *gladiator, int i);


};


#endif //GLADIATORS_ARMY_H
