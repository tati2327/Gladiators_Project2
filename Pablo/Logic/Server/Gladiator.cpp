//
// Created by tati2327 on 15/04/19.
//
#include <iostream>
#include "Gladiator.h"

Gladiator::Gladiator() {
    this->emotionalInt=0;
    this->anger=0;
    this->selfcontrol=0;
    this->lowerTrunckStrenght=0;
    this->upperTrunckStrenght=0;
    this->resistance=0;
    this->survivalProb=0;
    this->id=0;
    this->age=15;
    this->physicalCondition=0;
    this->expectedGenerations=0;
}
int Gladiator::calculateFitness() {
    fitness= resistance+expectedGenerations+survivalProb;
    return fitness;
}
int Gladiator::calculateResistance() {
    double resistanceTemp = (calculateEmotionalInt() * 0.10) + (lowerTrunckStrenght * 0.27) +
                            (upperTrunckStrenght*0.27) + (physicalCondition*0.26);

    if (15<=age && age<=20){
        resistanceTemp = resistanceTemp + (3 * 0.10);
        cout<<"resistance+4"<<endl;
    }else if (20<age && age<=30){
        resistanceTemp = resistanceTemp + (10 * 0.10);
        cout<<"resistance+10"<<endl;
    }else if(30<age && age<=40){
        resistanceTemp = resistanceTemp + (7 * 0.10);
        cout<<"resistance+8"<<endl;
    }else if(40<age && age<=50){
        resistanceTemp = resistanceTemp + (5 * 0.10);
        cout<<"resistance+6"<<endl;
    }else if(50<age && age<=60){
        resistanceTemp = resistanceTemp + (4 * 0.10);
        cout<<"resistance+4"<<endl;
    }if(60<age && age<=75){
        resistanceTemp = resistanceTemp + (2 * 0.10);
        cout<<"resistance+2"<<endl;
    }

    resistance = static_cast<int>(resistanceTemp * 10);
    return resistance;
}


int Gladiator::calculateEmotionalInt() {
    emotionalInt = anger+selfcontrol;
    return emotionalInt;
}

int Gladiator::calculateExpectedGenerations(int i) {
    expectedGenerations=((20-i)/6);
    return expectedGenerations;
}

int Gladiator::calculateSurvivalProb() {
    age = age+1;
    int newResistance = calculateResistance();
    survivalProb=((newResistance/270)*100);
    age=age-1;
    return survivalProb;
}

/*--------------------------------------GETTERS--------------------------------------------------------*/
int Gladiator::getSurvivalProb()  {
    return survivalProb;
}

int Gladiator::getEmotionalInt()  {
    return emotionalInt;
}

int Gladiator::getSelfControl()  {
    return selfcontrol;
}

int Gladiator::getAnger()  {
    return anger;
}

int Gladiator::getUpperTrunckStrenght()  {
    return upperTrunckStrenght;
}

int Gladiator::getLowerTrunckStrenght()  {
    return lowerTrunckStrenght;
}

int Gladiator::getResistance()  {
    return resistance;
}

int Gladiator::getAge()  {
    return age;
}

int Gladiator::getPhysicalCondition(){
    return physicalCondition;
}

int Gladiator::getId() {
    return id;
}
int Gladiator::getExpectedGenerations()   {
    return expectedGenerations;
}

int Gladiator::getFitness()  {
    return fitness;
}

/*-----------------------------------SETTERS-----------------------------------------------*/

void Gladiator::setId(int id) {
    Gladiator::id = id;
}

void Gladiator::setAge(int age) {
    Gladiator::age = age;
}

void Gladiator::setSurvivalProb(int survivalProb) {
    Gladiator::survivalProb = survivalProb;
}

void Gladiator::setExpectedGenerations(int expectedGenerations) {
    Gladiator::expectedGenerations = expectedGenerations;
}

void Gladiator::setEmotionalInt(int emotionalInt) {
    Gladiator::emotionalInt = emotionalInt;
}

void Gladiator::setSelfcontrol(int selfcontrol) {
    Gladiator::selfcontrol = selfcontrol;
}

void Gladiator::setAnger(int anger) {
    Gladiator::anger = anger;
}

void Gladiator::setUpperTrunckStrenght(int upperTrunckStrenght) {
    Gladiator::upperTrunckStrenght = upperTrunckStrenght;
}

void Gladiator::setLowerTrunckStrenght(int lowerTrunckStrenght) {
    Gladiator::lowerTrunckStrenght = lowerTrunckStrenght;
}

void Gladiator::setResistance(int resistance) {
    Gladiator::resistance = resistance;
}

void Gladiator::setPhysicalCondition(int physicalCondition) {
    Gladiator::physicalCondition = physicalCondition;
}

void Gladiator::setFitness(int fitness) {
    Gladiator::fitness = fitness;
}