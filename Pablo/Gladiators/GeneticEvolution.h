//
// Created by pablo on 17/04/19.
//

#ifndef GLADIATORS_GENETICEVOLUTION_H
#define GLADIATORS_GENETICEVOLUTION_H

#include "Army.h"
#include"Gladiator.h"


class GeneticEvolution {
    private:
        Army army;
        Gladiator fittest;
        Gladiator secondFittest;
        int generationCount;
    public:
        GeneticEvolution();
        void crossover();
        void mutation();
        List<int> fittestGenes();
        List<int> secondFittestGenes();



};



#endif //GLADIATORS_GENETICEVOLUTION_H
