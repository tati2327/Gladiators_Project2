#include "Army.h"
#include <iostream>

using namespace std;

Army::Army() {
    this->armySize=20;
}

Gladiator Army::getFittest() {
    fittest=gladiators[19];
    return fittest;
}

Gladiator Army::setValuesTipeA(Gladiator gladiator, int i) {
    gladiator.setId(i+1);
    cout<<"My id is:"<<gladiator.getId()<<endl;

    int random= (rand() % 2) + 1;
    gladiator.setAnger(random);
    cout<<gladiator.getAnger()<<endl;

    int random2= (rand() % 1) + 1;
    gladiator.setSelfcontrol(random2);
    cout<<gladiator.getSelfControl()<<endl;

    gladiator.setEmotionalInt(gladiator.calculateEmotionalInt());
    cout<<"EI"<<gladiator.getEmotionalInt()<<endl;

    int random4= (rand() % 2) + 1;
    gladiator.setPhysicalCondition(random4);
    cout<<"PC "<<gladiator.getPhysicalCondition()<<endl;

    int random5= (rand() % 3) + 1;
    gladiator.setUpperTrunckStrenght(random5);
    cout<<"UTS "<<gladiator.getUpperTrunckStrenght()<<endl;

    int random6= (rand() % 2) + 1;
    gladiator.setLowerTrunckStrenght(random6);
    cout<<"LTS "<<gladiator.getLowerTrunckStrenght()<<endl;

    int random7= rand() % 5 + 15;
    gladiator.setAge(random7);
    cout<<"Edad "<<gladiator.getAge()<<endl;

    gladiator.setResistance(gladiator.calculateResistance());
    cout<<"R "<<gladiator.getResistance()<<endl;


    gladiator.setExpectedGenerations(gladiator.calculateExpectedGenerations(i));
    cout<<"Expected"<<gladiator.getExpectedGenerations()<<endl;

    gladiator.setSurvivalProb(gladiator.calculateSurvivalProb());
    cout<<"survival"<<gladiator.getSurvivalProb()<<endl;

    gladiator.setFitness(gladiator.calculateFitness());
    cout<<"Fitness "<<gladiator.getFitness()<<endl;
    cout<<"Se creo un nuevo gladeador"<<endl;
    return gladiator;
}

Gladiator Army::setValuesTipeB(Gladiator gladiator, int i) {
    gladiator.setId(i+1);
    cout<<"My id is:"<<gladiator.getId()<<endl;

    int random= (rand() % 2) + 1;
    gladiator.setAnger(random);
    cout<<gladiator.getAnger()<<endl;

    int random2= (rand() % 2) + 1;
    gladiator.setSelfcontrol(random2);
    cout<<gladiator.getSelfControl()<<endl;

    gladiator.setEmotionalInt(gladiator.calculateEmotionalInt());
    cout<<"EI"<<gladiator.getEmotionalInt()<<endl;

    int random4= (rand() % 2) + 1;
    gladiator.setPhysicalCondition(random4);
    cout<<"PC "<<gladiator.getPhysicalCondition()<<endl;

    int random5= (rand() % 1) + 1;
    gladiator.setUpperTrunckStrenght(random5);
    cout<<"UTS "<<gladiator.getUpperTrunckStrenght()<<endl;

    int random6= (rand() % 1) + 1;
    gladiator.setLowerTrunckStrenght(random6);
    cout<<"LTS "<<gladiator.getLowerTrunckStrenght()<<endl;

    int random7= rand() % 10 + 50;
    gladiator.setAge(random7);
    cout<<"Edad "<<gladiator.getAge()<<endl;

    gladiator.setResistance(gladiator.calculateResistance());
    cout<<"R "<<gladiator.getResistance()<<endl;

    gladiator.setExpectedGenerations(gladiator.calculateExpectedGenerations(i));
    cout<<"Expected"<<gladiator.getExpectedGenerations()<<endl;

    gladiator.setSurvivalProb(gladiator.calculateSurvivalProb());
    cout<<"survival"<<gladiator.getSurvivalProb()<<endl;

    gladiator.setFitness(gladiator.calculateFitness());
    cout<<"Fitness "<<gladiator.getFitness()<<endl;
    cout<<"Se creo un nuevo gladeador"<<endl;
    return gladiator;
}

Gladiator Army::setValuesTipeC(Gladiator gladiator, int i) {
    gladiator.setId(i+1);
    cout<<"My id is:"<<gladiator.getId()<<endl;

    int random= (rand() % 2) + 1;
    gladiator.setAnger(random);
    cout<<gladiator.getAnger()<<endl;

    int random2= (rand() % 2) + 1;
    gladiator.setSelfcontrol(random2);
    cout<<gladiator.getSelfControl()<<endl;

    gladiator.setEmotionalInt(gladiator.calculateEmotionalInt());
    cout<<"EI"<<gladiator.getEmotionalInt()<<endl;

    int random4= (rand() % 2) + 1;
    gladiator.setPhysicalCondition(random4);
    cout<<"PC "<<gladiator.getPhysicalCondition()<<endl;

    int random5= (rand() % 1) + 1;
    gladiator.setUpperTrunckStrenght(random5);
    cout<<"UTS "<<gladiator.getUpperTrunckStrenght()<<endl;

    int random6= (rand() % 1) + 1;
    gladiator.setLowerTrunckStrenght(random6);
    cout<<"LTS "<<gladiator.getLowerTrunckStrenght()<<endl;

    int random7= rand() % 15 + 60;
    gladiator.setAge(random7);
    cout<<"Edad "<<gladiator.getAge()<<endl;

    gladiator.setResistance(gladiator.calculateResistance());
    cout<<"R "<<gladiator.getResistance()<<endl;


    gladiator.setExpectedGenerations(gladiator.calculateExpectedGenerations(i));
    cout<<"Expected"<<gladiator.getExpectedGenerations()<<endl;

    gladiator.setSurvivalProb(gladiator.calculateSurvivalProb());
    cout<<"survival"<<gladiator.getSurvivalProb()<<endl;

    gladiator.setFitness(gladiator.calculateFitness());
    cout<<"Fitness "<<gladiator.getFitness()<<endl;
    cout<<"Se creo un nuevo gladeador"<<endl;
    return gladiator;}

void Army::createArmy(int armySize) {
    for (int i = 0; i <= armySize-1; i++) {
        Gladiator gladiator;
        int random = rand() % 100 + 1;
        if(random<= 60){
            /*! Crear ejercito tipo C (60%)*/
            gladiators.add(setValuesTipeC(gladiator, i));
        }else if(60< random && random <=90){
            /*! Crear ejercito tipo B (30%)*/
            gladiators.add(setValuesTipeB(gladiator, i));
        }else if(90< random && random <=100){
            /*! Crear ejercito tipo A (10%)*/
            gladiators.add(setValuesTipeA(gladiator, i));
        }
    }
}

void Army:: printArray(List<Gladiator> gladiators, int n) {
    for (int i = 0; i < n; ++i) {
        cout << gladiators[i].getFitness() << " " << std::flush;
        cout <<"Emotional  "<< gladiators[i].getEmotionalInt() << " " << std::flush;
        std::cout << std::endl;
    }
}

void Army:: insertionSort(List<Gladiator> gladiators) {
    int size = gladiators.size();
    int swap = 1;
    if (size > 1) {
        while (swap > 0) {
            swap = 0;
            for (int i = 1; i < size; ++i) {
                int j = i - 1;
                if (gladiators[j].getFitness() > gladiators[i].getFitness()) {
                    Node<Gladiator> temp;
                    temp.setData(gladiators.getData(j));
                    gladiators.getNode(j)->setNode(gladiators.getNode(i));
                    gladiators.getNode(i)->data = temp.data;
                    swap += 1;
                }
            }
        }
    }
}

