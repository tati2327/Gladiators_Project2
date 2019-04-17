//
// Created by pablo on 17/04/19.
//

#include "GeneticEvolution.h"

GeneticEvolution::GeneticEvolution() {
    this->fittest;
    this->secondFittest;
    this->generationCount=0;
}

void GeneticEvolution::setFittest() {
    fittest=army.gladiators[19];
}

void GeneticEvolution::setSecondFittest() {
        secondFittest=army.gladiators[18];
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
    int random= (rand() % 7) + 0;
    for(int i=0; i<=random; i++){
       if(i==0) {
           tmp1.setAge(fittestList[i]);
           tmp2.setPhysicalCondition(secondFittestList[7]);
       }
       if(i==1) {
           tmp1.setUpperTrunckStrenght(fittestList[i]);
           tmp2.setSelfcontrol(secondFittestList[6]);
       }
       if(i==2) {
           tmp1.setLowerTrunckStrenght(fittestList[i]);
           tmp2.setSadness(secondFittestList[5]);
       }
       if(i==3) {
           tmp1.setAnger(fittestList[i]);
           tmp2.setJoy(secondFittestList[4]);
       }
       if(i==4) {
           tmp1.setJoy(fittestList[i]);
           tmp2.setAnger(secondFittestList[3]);
       }
       if(i==5) {
           tmp1.setSadness(fittestList[i]);
           tmp2.setLowerTrunckStrenght(secondFittestList[2]);
       }
       if(i==6) {
           tmp1.setSelfcontrol(fittestList[i]);
           tmp2.setUpperTrunckStrenght(secondFittestList[1]);
       }
       if(i==7) {
           tmp1.setPhysicalCondition(fittestList[i]);
           tmp2.setAge(secondFittestList[0]);
       }
    }
    if(random==7) {
        /*! Se asignan a tmp1 y tm2 los atributos que son de "calcular" y los que no se heredan de sus padres.*/
        tmp1.setId(20 + generationCount + 1);
        tmp1.setEmotionalInt(tmp1.calculateEmotionalInt());
        tmp1.setResistance(tmp1.calculateFitness());
        tmp2.setId(20 + generationCount + 2);
        tmp2.setEmotionalInt(tmp2.calculateEmotionalInt());
        tmp2.setResistance(tmp2.calculateFitness());
        /*! Se asigna tmp1 y tmp2 al gladiador menos apto y el segundo menos apto respectivamente*/
        army.gladiators[0]=tmp1;
        army.gladiators[1]=tmp2;
        /*! Se reordena la lista de gladiadores*/
        army.insertionSort(army.gladiators);
        army.printArray(army.gladiators, army.armySize);
        return;

    }
    for(int i=random+1; i<=7; i++){
        if(i==0) {
            tmp1.setAge(secondFittestList[i]);
            tmp2.setPhysicalCondition(fittestList[7]);
        }
        if(i==1) {
            tmp1.setUpperTrunckStrenght(secondFittestList[i]);
            tmp2.setSelfcontrol(fittestList[6]);
        }
        if(i==2) {
            tmp1.setLowerTrunckStrenght(secondFittestList[i]);
            tmp2.setSadness(fittestList[5]);
        }
        if(i==3) {
            tmp1.setAnger(secondFittestList[i]);
            tmp2.setJoy(fittestList[4]);
        }
        if(i==4) {
            tmp1.setJoy(secondFittestList[i]);
            tmp2.setAnger(fittestList[3]);
        }
        if(i==5) {
            tmp1.setSadness(secondFittestList[i]);
            tmp2.setLowerTrunckStrenght(fittestList[2]);
        }
        if(i==6) {
            tmp1.setSelfcontrol(secondFittestList[i]);
            tmp2.setUpperTrunckStrenght(fittestList[1]);
        }
        if(i==7) {
            tmp1.setPhysicalCondition(secondFittestList[i]);
            tmp2.setAge(fittestList[0]);
        }
    }
    /*! Se asignan a tmp1 y tm2 los atributos que son de "calcular" y los que no se heredan de sus padres.*/
    tmp1.setId(20 + generationCount + 1);
    tmp1.setEmotionalInt(tmp1.calculateEmotionalInt());
    tmp1.setResistance(tmp1.calculateFitness());
    tmp2.setId(20 + generationCount + 2);
    tmp2.setEmotionalInt(tmp2.calculateEmotionalInt());
    tmp2.setResistance(tmp2.calculateFitness());

    cout<<"El nuevo valor es: "<<tmp1.getLowerTrunckStrenght()<<endl;
    cout<<"El nuevo valor es: "<<tmp2.getLowerTrunckStrenght()<<endl;


    /*! Se asigna tmp1 y tmp2 al gladiador menos apto y el segundo menos apto respectivamente*/
    army.gladiators.getNode(0)->setData(tmp1);
    cout<<"El nuevo valor del mansote 0 es: "<<army.gladiators[0].getResistance()<<endl;
    army.gladiators.getNode(1)->setData(tmp2);
    cout<<"El nuevo valor del mansote 1 es: "<<army.gladiators[1].getResistance()<<endl;
    /*! Se reordena la lista de gladiadores*/
    army.insertionSort(army.gladiators);
    army.printArray(army.gladiators, army.armySize);
    return;


}




