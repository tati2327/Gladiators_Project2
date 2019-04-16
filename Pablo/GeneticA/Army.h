//
// Created by pablo on 15/04/19.
//

#ifndef GENETICA_ARMY_H
#define GENETICA_ARMY_H
#include "Gladiator.h"
#include <cstdlib>
#include <ctime>


class Army {
public:
        int armySize;
        Gladiator *gladiators[];


public:
    Army(int armySize);
    void printArray(int *array, int n);

    void insertionSort(int arr[], int arr_size);
    void createArmy(int armySize);
    Gladiator* setRandomValues(Gladiator *gladiator, int i);
    Gladiator* setHeuristicValues(Gladiator *gladiator, int i);


};


#endif //GENETICA_ARMY_H
