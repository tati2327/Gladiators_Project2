//
// Created by pablo on 17/04/19.
//

#ifndef GLADIATORS_GENETICEVOLUTION_H
#define GLADIATORS_GENETICEVOLUTION_H

#include "Army.h"
#include"Gladiator.h"
#include "Gladiator.h"
#include <sstream>
#include <string>
#include <iostream>

using namespace std;


class GeneticEvolution {
    public:
        int generationCount;
    public:
        GeneticEvolution();
        void crossover(Army army);
        void mutation(Army army);
        int changeValue(int value);
        List<int> fittestGenes(Army army);
        List<int> secondFittestGenes(Army army);

        long long decimalToBinary(int n);


        int binaryToDecimal(long long n);




};



#endif //GLADIATORS_GENETICEVOLUTION_H
