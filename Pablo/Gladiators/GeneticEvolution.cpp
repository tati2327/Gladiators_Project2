//
// Created by pablo on 17/04/19.
//

#include "GeneticEvolution.h"

GeneticEvolution::GeneticEvolution() {
    this->fittest=army.gladiators[19];
    this->secondFittest=army.gladiators[18];
    this->generationCount=0;
}

List<int> GeneticEvolution::fittestGenes() {
    List<int> fittestList;
    fittestList.add(fittest.getAge());
    fittestList.add(fittest.getUpperTrunckStrenght());
    fittestList.add(fittest.getLowerTrunckStrenght());
    fittestList.add(fittest.getAnger());
    fittestList.add(fittest.getJoy());
    fittestList.add(fittest.getSadness());
    fittestList.add(fittest.getSelfControl());
    fittestList.add(fittest.getPhysicalCondition());
    return fittestList;
}

List<int> GeneticEvolution::secondFittestGenes() {
    List<int> secondFittestList;
    secondFittestList.add(secondFittest.getAge());
    secondFittestList.add(secondFittest.getUpperTrunckStrenght());
    secondFittestList.add(secondFittest.getLowerTrunckStrenght());
    secondFittestList.add(secondFittest.getAnger());
    secondFittestList.add(secondFittest.getJoy());
    secondFittestList.add(secondFittest.getSadness());
    secondFittestList.add(secondFittest.getSelfControl());
    secondFittestList.add(secondFittest.getPhysicalCondition());
    return secondFittestList;
}




void GeneticEvolution::crossover() {
    Gladiator tmp1;
    Gladiator tmp2;
    List<int> fittestList= fittestGenes();
    List<int> secondFittestList= secondFittestGenes();
    srand(time(NULL));
    int random= (rand() % 7) + 0;
    for(int i=0; i<=random; i++){
        switch (i){
            case 0:
                tmp1.setAge(fittestList[i]);
                tmp2.setPhysicalCondition(secondFittestList[7]);

            case 1:
                tmp1.setUpperTrunckStrenght(fittestList[i]);
                tmp2.setSelfcontrol(secondFittestList[6]);

            case 2:
                tmp1.setLowerTrunckStrenght(fittestList[i]);
                tmp2.setSadness(secondFittestList[5]);

            case 3:
                tmp1.setAnger(fittestList[i]);
                tmp2.setJoy(secondFittestList[4]);

            case 4:
                tmp1.setJoy(fittestList[i]);
                tmp2.setAnger(secondFittestList[3]);

            case 5:
                tmp1.setSadness(fittestList[i]);
                tmp2.setLowerTrunckStrenght(secondFittestList[2]);

            case 6:
                tmp1.setSelfcontrol(fittestList[i]);
                tmp2.setUpperTrunckStrenght(secondFittestList[1]);
            case 7:
                tmp1.setPhysicalCondition(fittestList[i]);
                tmp2.setAge(secondFittestList[0]);
        }
    }
    if(random==7) {
        tmp1.setId(20 + generationCount + 1);
        tmp1.setEmotionalInt(tmp1.calculateEmotionalInt());
        tmp1.setResistance(tmp1.calculateFitness());
        tmp2.setId(20 + generationCount + 2);
        tmp2.setEmotionalInt(tmp1.calculateEmotionalInt());
        tmp2.setResistance(tmp1.calculateFitness());
        /*///////////////////////////////////////////////////////////////FALTA AQUEL BRETE/////////////////////////////*/
        return;

    }for(int i=random+1; i<=7; i++){
        switch (i){
            case 0:
                tmp1.setAge(fittestList[i]);
                tmp2.setPhysicalCondition(fittestList[7]);

            case 1:
                tmp1.setUpperTrunckStrenght(fittestList[i]);
                tmp2.setSelfcontrol(fittestList[6]);

            case 2:
                tmp1.setLowerTrunckStrenght(fittestList[i]);
                tmp2.setSadness(fittestList[5]);

            case 3:
                tmp1.setAnger(fittestList[i]);
                tmp2.setJoy(fittestList[4]);

            case 4:
                tmp1.setJoy(fittestList[i]);
                tmp2.setAnger(fittestList[3]);

            case 5:
                tmp1.setSadness(fittestList[i]);
                tmp2.setLowerTrunckStrenght(fittestList[2]);

            case 6:
                tmp1.setSelfcontrol(fittestList[i]);
                tmp2.setUpperTrunckStrenght(fittestList[1]);
            case 7:
                tmp1.setPhysicalCondition(fittestList[i]);
                tmp2.setAge(fittestList[0]);
        }
    }


}




