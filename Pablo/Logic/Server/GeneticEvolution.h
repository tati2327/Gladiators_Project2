//
// Created by pablo on 17/04/19.
//

#ifndef GLADIATORS_GENETICEVOLUTION_H
#define GLADIATORS_GENETICEVOLUTION_H

#include "Army.h"

#include "Army.h"
#include "Gladiator.h"

class GeneticEvolution {
public:
    int generationCount;/*!Contador para saber cual es el numero de generacion*/
    string crossingMask1;/*! "Molde1" para saber si tomar un cromosoma de un padre u otro */
    string crossingMask2;/*! "Molde2" para saber si tomar un cromosoma de un padre u otro */
    string crossingMask3;/*! "Molde3" para saber si tomar un cromosoma de un padre u otro */
    int lastId; /*!Contador para que ayuda para calcular el ID de los nuevos gladiadores */
    List<Gladiator> newGladiators;



    GeneticEvolution();
    /*!
     * Crossover realiza el cruce genetico entre los mejores gladiadores
     * @param army instancia del ejercito
     * @param index1 indice para obtener el padre1
     * @param index2 indice para obtener el padre2
     */
    void crossover(Army army,int index1, int index2);

    /*!
     * mutation realiza la mutacion a un nuevo gladiador
     * @param gladiator instancia de un gladiador
     */
    void mutation(Gladiator &gladiator);

    /*!
     * invertion realiza la inversion de un gladiador nuevo
     * @param gladiator instancia de un gladiador
     */
    void invertion(Gladiator &gladiator);

    /*!
     * convertToString pasa un atributo de tipo integer a string.
     * @param trait atributo del gladiador que se quiere pasar a string
     * @param type  parametro que si es 1 indica que el gen es cualquiera menos anger o selfControl
     * @return
     */
    string convertToString(int trait, int type);

    /*!
     * convertToDecimal pasa un atributo de tipo string a integer
     * @param trait atributo del gladiador que se quiere pasar a integer
     * @param type parametro que si es 1 indica que el gen es cualquiera menos anger o selfControl
     * @return
     */
    int convertToDecimal(string trait, int type);

    /*!
     * makeExchange se encarga de otorgar los cromosomas que van integrar un gen de un hijo
     * @param parent1 cadena de cromosomas de un gen del padre 1
     * @param parent2 cadena de cromosomas de un gen del padre 2
     * @param son  cadena de cromosomas de un hijo
     * @param type parametro que si es 1 indica que el gen es cualquiera menos anger o selfControl
     * @return
     */
    int makeExchange(string parent1,string parent2,string son,int type);

    /*!
     * updateAge realiza el aumento de edad de cada gladiador despues de un cambio generacional
     * @param army instancia del ejercito
     */
    void updateAge(Army army);

    /*!
     * invertGene aplica el complemento a la codena de cromosomas
     * @param value  cadena de cromosomas
     * @param type parametro que si es 1 indica que el gen es cualquiera menos anger o selfControl
     * @return
     */
    int invertGene(string value, int type);

    /*!
     * mutateChromosome muta un cromosoma de un gen
     * @param value cadena de cromosomas
     * @param type parametro que si es 1 indica que el gen es cualquiera menos anger o selfControl
     * @return
     */
    int mutateChromosome(string value, int type);

    /*!
     * addNewGladiator agrega los gladiadores de cada generación a una lista historica de todos los gladiadores
     * @param newGladiator
     * @param army
     */
    void addNewGladiators(List<Gladiator> newGladiator, Army army);
};




#endif //GLADIATORS_GENETICEVOLUTION_H
