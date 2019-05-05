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
    int lastId;



    GeneticEvolution();

    void applyEvolution();
    void crossover(Army army,int index1, int index2);
    void mutation(Gladiator gladiator);
    string convertToString(int trait, int type);
    int convertToDecimal(string trait, int type);
    int makeExchange(string parent1,string parent2,string son,int type);

    void updateAge(Army army);
    int changeValue(string value,int type);

};



#endif //GLADIATORS_GENETICEVOLUTION_H
