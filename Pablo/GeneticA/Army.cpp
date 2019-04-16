//
// Created by pablo on 15/04/19.
//

#include "Army.h"
#include <iostream>

using namespace std;

Army::Army(int armySize ) {
    this->armySize=20;

}


Gladiator* Army::setRandomValues(Gladiator *gladiator, int i) {
    gladiator->setId(i+1);
    cout<<"My id is:"<<gladiator->getId()<<endl;

    srand((int)time(0));
    int random= (rand() % 5) + 0;
    gladiator->setAnger(random);
    cout<<gladiator->getAnger()<<endl;

    int random1= (rand() % 5) + 0;
    gladiator->setJoy(random1);
    cout<<gladiator->getJoy()<<endl;

    int random2= (rand() % 5) + 0;
    gladiator->setSelfcontrol(random2);
    cout<<gladiator->getSelfControl()<<endl;


    int random3= (rand() % 5) + 0;
    gladiator->setSadness(random3);
    cout<<gladiator->getSadness()<<endl;

    gladiator->setEmotionalInt(gladiator->calculateEmotionalInt());
    cout<<"Inteligencia Emocional, inicie aqui zorro :"<<gladiator->getEmotionalInt()<<endl;

    int random4= (rand() % 20) + 0;
    gladiator->setPhysicalCondition(random4);
    cout<<gladiator->getPhysicalCondition()<<endl;

    int random5= (rand() % 20) + 0;
    gladiator->setUpperTrunckStrenght(random5);
    cout<<gladiator->getUpperTrunckStrenght()<<endl;

    int random6= (rand() % 20) + 0;
    gladiator->setLowerTrunckStrenght(random6);
    cout<<gladiator->getLowerTrunckStrenght()<<endl;

    int random7= (rand() % 40) + 0;
    gladiator->setAge(random7);
    cout<<"edad"<<gladiator->getAge()<<endl;

    gladiator->setResistance(gladiator->calculateFitness());
    cout<<gladiator->getResistance()<<endl;
    cout<<"Termine RASTAMAN"<<endl;

}


Gladiator* Army::setHeuristicValues(Gladiator *gladiator, int i) {
    gladiator->setId(i+1);
    cout<<"My id is:"<<gladiator->getId()<<endl;

    gladiator->setAnger(2);
    cout<<gladiator->getAnger()<<endl;


    gladiator->setJoy(3);
    cout<<gladiator->getJoy()<<endl;


    gladiator->setSelfcontrol(3);
    cout<<gladiator->getSelfControl()<<endl;



    gladiator->setSadness(3);
    cout<<gladiator->getSadness()<<endl;

    gladiator->setEmotionalInt(gladiator->calculateEmotionalInt());
    cout<<"Inteligencia Emocional, inicie aqui zorro :"<<gladiator->getEmotionalInt()<<endl;


    gladiator->setPhysicalCondition(18);
    cout<<gladiator->getPhysicalCondition()<<endl;


    gladiator->setUpperTrunckStrenght(3);
    cout<<gladiator->getUpperTrunckStrenght()<<endl;


    gladiator->setLowerTrunckStrenght(18);
    cout<<gladiator->getLowerTrunckStrenght()<<endl;


    gladiator->setAge(17);
    cout<<"edad"<<gladiator->getAge()<<endl;

    gladiator->setResistance(gladiator->calculateFitness());
    cout<<gladiator->getResistance()<<endl;

}


void Army::createArmy(int armySize) {
    for (int i = 0; i <= armySize-3; i++) {
        Gladiator *gladiator = new Gladiator();

        if(i==0) {
            gladiators[i] = setHeuristicValues(gladiator, i);

        }else {
            gladiators[i] = setRandomValues(gladiator, i);

        }
    }
    int i=0;
    cout<<gladiators[5]->getResistance()<<endl;
    cout<<gladiators[10]->getResistance()<<endl;
    while(i<=20){
        cout<<gladiators[i]<<endl;
        i++;
    }
}



void Army:: printArray(int *array, int n) {
    for (int i = 0; i < n; ++i)
        std::cout << array[i] << " " << std::flush;
    std::cout << std::endl;
}



void Army:: insertionSort(int arr[], int arr_size){
    if(arr_size > 1){
        int size = arr_size;
        for(int i = 1; i < size; ++i){
            int j = i - 1;
            int key = arr[i];
            while(j >= 0 && arr[j] > key){
                arr[j+1] = arr[j];
                --j;
            }
            arr[j+1] = key;
        }
    }
}



