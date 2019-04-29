//
// Created by tati2327 on 15/04/19.
//

#include <iostream>
#include "Gladiator.h"


Gladiator::Gladiator() {
    this->emotionalInt=0;
    this->joy=0;
    this->anger=0;
    this->sadness=0;
    this->selfcontrol=0;
    this->lowerTrunckStrenght=0;
    this->upperTrunckStrenght=0;
    this->resistance=0;
    this->survivalProb=0;
    this->id=0;
    this->age=0;
    this->physicalCondition=0;
    this->expectedGenerations=0;


}

int Gladiator::calculateFitness() {
    resistance= calculateEmotionalInt() + lowerTrunckStrenght +
                upperTrunckStrenght + physicalCondition;
    if (age==0)
        return resistance;

    if (20<age && age<=30){
        resistance=resistance+10;
        cout<<"resistance+10"<<endl;
    }
    if (15<=age && age<=20){
        resistance=resistance+4;
        cout<<"resistance+4"<<endl;

    }
    if(30<age && age<=40){
        resistance=resistance+8;
        cout<<"resistance+8"<<endl;

    }
    return resistance;
}


int Gladiator::calculateEmotionalInt() {
    emotionalInt= anger+ sadness+ joy+ selfcontrol;
    return emotionalInt;
}











/*-----------------------------------------------------------GETTERS-----------------------------------------------------------------------------------*/
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



int Gladiator::getSadness()  {
    return sadness;
}



int Gladiator::getJoy()  {
    return joy;
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

int Gladiator::getId() const {
    return id;
}



/*------------------------------------------------------SETTERS-----------------------------------------------*/

void Gladiator::setId(int _id) {
    id = _id;
}

void Gladiator::setAge(int _age) {
    age = _age;
}

void Gladiator::setSurvivalProb(int _survivalProb) {
    survivalProb = _survivalProb;
}

void Gladiator::setExpectedGenerations(int _expectedGenerations) {
    expectedGenerations = _expectedGenerations;
}

void Gladiator::setEmotionalInt(int _emotionalInt) {
    emotionalInt = _emotionalInt;
}

void Gladiator::setSelfcontrol(int _selfcontrol) {
    selfcontrol = _selfcontrol;
}

void Gladiator::setAnger(int _anger) {
    anger = _anger;
}

void Gladiator::setSadness(int _sadness) {
    sadness = _sadness;
}

void Gladiator::setJoy(int _joy) {
    joy = _joy;
}

void Gladiator::setUpperTrunckStrenght(int _upperTrunckStrenght) {
    upperTrunckStrenght = _upperTrunckStrenght;
}

void Gladiator::setLowerTrunckStrenght(int _lowerTrunckStrenght) {
    lowerTrunckStrenght = _lowerTrunckStrenght;
}

void Gladiator::setResistance(int _resistance) {
    resistance = _resistance;
}


void Gladiator::setPhysicalCondition(int _physicalCondition) {
    physicalCondition = _physicalCondition;
}

int Gladiator::getExpectedGenerations() const {
    return expectedGenerations;
}

int Gladiator::getSelfcontrol() const {
    return selfcontrol;
}
