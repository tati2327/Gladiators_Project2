#include "Army.h"
#include <iostream>

using namespace std;

Army::Army() {
    this->armySize=20;
}

Gladiator Army::setRandomValues(Gladiator gladiator, int i) {
    gladiator.setId(i+1);
    cout<<"My id is:"<<gladiator.getId()<<endl;

    int random= (rand() % 5) + 0;
    gladiator.setAnger(random);
    cout<<gladiator.getAnger()<<endl;

    int random1= (rand() % 5) + 0;
    gladiator.setJoy(random1);
    cout<<gladiator.getJoy()<<endl;

    int random2= (rand() % 5) + 0;
    gladiator.setSelfcontrol(random2);
    cout<<gladiator.getSelfControl()<<endl;

    int random3= (rand() % 5) + 0;
    gladiator.setSadness(random3);
    cout<<gladiator.getSadness()<<endl;

    gladiator.setEmotionalInt(gladiator.calculateEmotionalInt());
    cout<<"Inteligencia Emocional, inicie aqui zorro :"<<gladiator.getEmotionalInt()<<endl;

    int random4= (rand() % 20) + 0;
    gladiator.setPhysicalCondition(random4);
    cout<<gladiator.getPhysicalCondition()<<endl;

    int random5= (rand() % 20) + 0;
    gladiator.setUpperTrunckStrenght(random5);
    cout<<gladiator.getUpperTrunckStrenght()<<endl;

    int random6= (rand() % 20) + 0;
    gladiator.setLowerTrunckStrenght(random6);
    cout<<gladiator.getLowerTrunckStrenght()<<endl;

    int random7= (rand() % 40) + 0;
    gladiator.setAge(random7);
    cout<<"edad"<<gladiator.getAge()<<endl;

    gladiator.setResistance(gladiator.calculateFitness());
    cout<<gladiator.getResistance()<<endl;
    cout<<"Termine RASTAMAN"<<endl;

    return gladiator;
}


Gladiator Army::setHeuristicValues(Gladiator gladiator, int i) {
    gladiator.setId(i+1);
    cout<<"My id is:"<<gladiator.getId()<<endl;

    gladiator.setAnger(2);
    cout<<gladiator.getAnger()<<endl;

    gladiator.setJoy(3);
    cout<<gladiator.getJoy()<<endl;

    gladiator.setSelfcontrol(3);
    cout<<gladiator.getSelfControl()<<endl;

    gladiator.setSadness(3);
    cout<<gladiator.getSadness()<<endl;

    gladiator.setEmotionalInt(gladiator.calculateEmotionalInt());
    cout<<"Inteligencia Emocional, inicie aqui zorro :"<<gladiator.getEmotionalInt()<<endl;

    gladiator.setPhysicalCondition(18);
    cout<<gladiator.getPhysicalCondition()<<endl;

    gladiator.setUpperTrunckStrenght(3);
    cout<<gladiator.getUpperTrunckStrenght()<<endl;

    gladiator.setLowerTrunckStrenght(18);
    cout<<gladiator.getLowerTrunckStrenght()<<endl;

    gladiator.setAge(17);
    cout<<"edad"<<gladiator.getAge()<<endl;

    gladiator.setResistance(gladiator.calculateFitness());
    cout<<gladiator.getResistance()<<endl;

    return gladiator;
}


void Army::createArmy(int armySize) {
    srand(time(NULL));
    for (int i = 0; i <= armySize-1; i++) {
        Gladiator gladiator =Gladiator();
        if(i==0) {
            gladiators.add(setHeuristicValues(gladiator, i));
        }else {
            gladiators.add(setRandomValues(gladiator, i));
        }
    }
    int i=0;
    while(i<=19) {
        cout << "Sirve " << gladiators.getData(i).getResistance() << endl;
        i++;
    }
}




void Army:: printArray(List<Gladiator> gladiators, int n) {
    for (int i = 0; i < n; ++i)
        cout << gladiators[i].getResistance() << " " << std::flush;
    std::cout << std::endl;
}



void Army:: insertionSort(List<Gladiator> gladiators) {
    int size = gladiators.size();
    int swap = 1;
    if (size > 1) {
        while (swap > 0) {
            swap = 0;
            for (int i = 1; i < size; ++i) {
                int j = i - 1;
                //cout << "j es " << j << endl;
                //cout << "i es " << i << endl;
                if (gladiators[j].getResistance() > gladiators[i].getResistance()) {
                    Node<Gladiator> temp;
                    temp.setData(gladiators.getData(j));
                    gladiators.getNode(j)->setNode(gladiators.getNode(i));
                    gladiators.getNode(i)->data = temp.data;
                    swap += 1;
                    //cout << "swapping" << endl;
                }
                //this->printArray(gladiators, 20);
            }
        }
    }
}