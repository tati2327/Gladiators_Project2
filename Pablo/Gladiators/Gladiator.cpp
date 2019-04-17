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


long long decimalToBinary(int n)
{
    long long binaryNumber = 0;
    int remainder, i = 1, step = 1;

    while (n!=0)
    {
        remainder = n%2;
        cout << "Step " << step++ << ": " << n << "/2, Remainder = " << remainder << ", Quotient = " << n/2 << endl;
        n /= 2;
        binaryNumber += remainder*i;
        i *= 10;
    }
    return binaryNumber;
}



int binaryToDecimal(long long n)
{
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
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

void Gladiator::setSadness(int sadness) {
    Gladiator::sadness = sadness;
}

void Gladiator::setJoy(int joy) {
    Gladiator::joy = joy;
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