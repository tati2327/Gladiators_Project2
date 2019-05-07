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
    Gladiator fittest;

    int armySize;
    List<Gladiator> gladiators;

public:
    Army();
    Gladiator getFittest();

    void printArray(List<Gladiator> gladiators, int n);
    void insertionSort(List<Gladiator> gladiators);
    void createArmy(int armySize);
    Gladiator setValuesTipeA(Gladiator gladiator, int i);
    Gladiator setValuesTipeB(Gladiator gladiator, int i);
    Gladiator setValuesTipeC(Gladiator gladiator, int i);

};


#endif //GLADIATORS_ARMY_H
