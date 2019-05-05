//
// Created by pablo on 17/04/19.
//

#ifndef GLADIATORS_GENETICEVOLUTION_H
#define GLADIATORS_GENETICEVOLUTION_H

#include "Army.h"

#include "Army.h"
#include "Gladiator.h"

class GeneticEvolution {
public:
    int generationCount;
    string crossingmask1;
    string crossingmask2;
    string crossingmask3;
    Gladiator parent1;



    GeneticEvolution();

    void applyEvolution();
    void crossover(Army army,int index1, int index2, int idCount);
    void mutation(Gladiator gladiator);
    string convertToString(int trait, int type);
    int convertToDecimal(string trait);
    int makeExchange(string parent1,string parent2,string son);

    int changeValue(int value);
    long long decimalToBinary(int n);
    int binaryToDecimal(long long n);
};



#endif //GLADIATORS_GENETICEVOLUTION_H
