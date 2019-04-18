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
        Army army;
        Gladiator fittest;
        Gladiator secondFittest;
        int generationCount;
    public:
        GeneticEvolution();
        void setFittest();
        void setSecondFittest();
        void crossover();
        void mutation();
        int changeValue(int value);
        List<int> fittestGenes();
        List<int> secondFittestGenes();

        long long decimalToBinary(int n);


        int binaryToDecimal(long long n);




};



#endif //GLADIATORS_GENETICEVOLUTION_H
