//
// Created by tati2327 on 15/04/19.
//

#ifndef GLADIATORS_GLADIATOR_H
#define GLADIATORS_GLADIATOR_H
#include <cmath>

using namespace std;

class Gladiator {
private:
    int id, age, survivalProb, expectedGenerations, emotionalInt, selfcontrol, anger,
            upperTrunckStrenght, lowerTrunckStrenght, resistance, physicalCondition, fitness;
public:
    int getExpectedGenerations() const;

    int getSelfcontrol() const;

    int getFitness() const;

    void setFitness(int fitness);

public:
    Gladiator();

    /*!
     * Funcion para valorar la aptitud de un gladiador
     * @return
     */
    int calculateResistance();
    int calculateEmotionalInt();
    int calculateFitness();

    /*----------------------------------GETTERS------------------------------------------------*/
    int getSurvivalProb() ;
    int getEmotionalInt() ;
    int getSelfControl() ;
    int getAnger() ;
    int getUpperTrunckStrenght() ;
    int getLowerTrunckStrenght() ;
    int getResistance() ;
    int getAge() ;
    int getPhysicalCondition();
    int getId() ;
    int getExpectedGenerations();
    int getFitness();

    /*------------------------------------SETTERS---------------------------------------------*/
    void setId(int id);
    void setAge(int age);
    void setSurvivalProb(int i);
    void setExpectedGenerations(int i);
    void setEmotionalInt(int i);
    void setSelfcontrol(int i);
    void setAnger(int i);
    void setUpperTrunckStrenght(int i);
    void setLowerTrunckStrenght(int i);
    void setResistance(int i);
    void setPhysicalCondition(int i);
};

#endif //GLADIATORS_GLADIATOR_H
