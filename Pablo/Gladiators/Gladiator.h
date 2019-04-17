//
// Created by tati2327 on 15/04/19.
//

#ifndef GLADIATORS_GLADIATOR_H
#define GLADIATORS_GLADIATOR_H
#include <cmath>

using namespace std;

class Gladiator {
private:
    int id, age, survivalProb, expectedGenerations, emotionalInt, selfcontrol, anger, sadness, joy,
            upperTrunckStrenght, lowerTrunckStrenght, resistance, physicalCondition;

public:
    Gladiator();
    int calculateFitness();

    int calculateEmotionalInt();

    long long decimalToBinary(int n);


    int binaryToDecimal(long long n);


/*------------------------------------------------------------GETTERS-------------------------------------------------------------------------------*/

    int getSurvivalProb() ;

    int getEmotionalInt() ;

    int getSelfControl() ;

    int getAnger() ;

    int getSadness() ;

    int getJoy() ;

    int getUpperTrunckStrenght() ;

    int getLowerTrunckStrenght() ;

    int getResistance() ;

    int getAge() ;

    int getPhysicalCondition();

    int getId() const;


/*----------------------------------------------------------SETTERS---------------------------------------------*/
    void setId(int id);

    void setAge(int age);

    void setSurvivalProb(int i);

    void setExpectedGenerations(int i);

    void setEmotionalInt(int i);

    void setSelfcontrol(int i);

    void setAnger(int i);

    void setSadness(int i);

    void setJoy(int i);

    void setUpperTrunckStrenght(int i);

    void setLowerTrunckStrenght(int i);

    void setResistance(int i);

    void setPhysicalCondition(int i);

};

#endif //GLADIATORS_GLADIATOR_H
