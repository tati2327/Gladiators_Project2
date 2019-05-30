#ifndef GLADIATORS_GLADIATOR_H
#define GLADIATORS_GLADIATOR_H
#include <cmath>

using namespace std;

class Gladiator {
private:
    int id, age, expectedGenerations, emotionalInt, selfcontrol, anger,
            upperTrunckStrenght, lowerTrunckStrenght, resistance, physicalCondition, fitness;/*!Atributos de los gladiadores tipo int*/
    float survivalProb;/*!Atributo tipo float*/

public:
    Gladiator();
    /*!
     * calculateResistance calcula la resistencia del gladiador
     * @return
     */
    int calculateResistance();

    /*!
     * calculateEmotionalInt calcula la inteligencia emocional del gladiador
     * @return
     */
    int calculateEmotionalInt();

    /*!
     * calculateFitness calcula el fitness del gladiador
     * @return
     */
    int calculateFitness();

    /*!
     * calculateExpectedGenerations calcula las generaciones esperadas del gladiador
     * @param i
     * @return
     */
    int calculateExpectedGenerations(int i);

    /*!
     * calculateSurvivalProb calcula la probabilidad de supervivencia del gladiador en la siguiente generación
     * @return
     */
    float calculateSurvivalProb();

    /*----------------------------------GETTERS------------------------------------------------*/
    /*!
  * Getters
  */

    float getSurvivalProb() ;
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
    /*!
  * Setters
  */
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
    void setFitness(int fitness);
};

#endif //GLADIATORS_GLADIATOR_H
