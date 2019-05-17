//
// Created by pablo on 16/04/19.
//

#ifndef GLADIATORS_ARMY_H
#define GLADIATORS_ARMY_H


#include "Gladiator.h"
#include <cstdlib>
#include <ctime>
#include "List.h"
#include <unistd.h>

class Army {
public:
    Gladiator fittest;/*! Es el gladiador más fuerte de la generación */
    int armySize;/*! Tamaño de la lista de gladidores*/
    List<Gladiator> gladiators;/*! Lista de gladidores de cada generación*/

public:
    Army();
    /*!
     * getFittest obtiene el mejor gladidor de la generación
     * @return
     */
    Gladiator getFittest();

    /*!
     * printArray imprime la lista de gladidores
     * @param gladiators
     * @param n indica el tamaño de la lista
     */
    void printArray(List<Gladiator> gladiators, int n);

    /*!
     * insertionSort ordena la lista de menor a mayor fitness
     * @param gladiators
     */
    void insertionSort(List<Gladiator> gladiators);

    /*!
     * createArmy es la encargada de ir generando uno por uno a los gladidores de la población incial
     * @param armySize
     */
    void createArmy(int armySize);

    /*!
     * setValuesTypeA crea gladiadores con la mayor probabilidad de ser los mejores en la población inicial
     * @param gladiator
     * @param i número de indice del gladiador en la lista
     * @return
     */
    Gladiator setValuesTypeA(Gladiator gladiator, int i);

    /*!
     * setValuesTypeB crea gladiadores con una probabilidad intemedia de ser los mejores en la población inicial
     * @param gladiator
     * @param i número de indice del gladiador en la lista
     * @return
     */
    Gladiator setValuesTypeB(Gladiator gladiator, int i);

    /*!
     * setValuesTypeC crea gladiadores con la menor probabilidad de ser los mejores en la poclación inicial
     * @param gladiator
     * @param i número de indice del gladiador en la lista
     * @return
     */
    Gladiator setValuesTypeC(Gladiator gladiator, int i);

};


#endif //GLADIATORS_ARMY_H
