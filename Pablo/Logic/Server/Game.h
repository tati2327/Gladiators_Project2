#ifndef A_GAME_H
#define A_GAME_H

#include "Matrix.h"
#include "Field.h"
#include "Gladiator.h"
#include "Army.h"
#include "GeneticEvolution.h"
#include "Pathfinding.h"
#include "JSON.h"

class Game {
    public:
        int rows, columns;/*!Indica la fila y la columna respectivamente */
        Matrix<Field> board;/*!Tablero */
        Army army;/*!Instancia del ejercito */
        GeneticEvolution gE;/*!Instancia el la clase GeneticEvolution */
        Pathfinding myRoute;/*!Instancia de pathfinding */
        Gladiator myGladiator;/*!Instancia de gladiador*/
        List<string> obstaclesList;/*!Lista de obstaculos */
        List<Gladiator> historicalArmy;/*!Lista con todas las generaciones de gladiadores*/
        int error;/*!Funciona como un contador para cada vez que se presenta un error */
        List<int> resistance, upperStrenght, lowerStrenght, emotionalIntelligence, physicalCondition, age, expectedGenerations, fitness, id;
        List<float> survivalProb;/*! Listas que incluyen todas las caracteristicas historicas de cada gladiador*/


    Game();
        /*!
         * newGame se encarga de establecer la población inicial, agregar los obstaculos iniciales  y calular la ruta
         * @return
         */
        string newGame();

        /*!
         * play se encarga de llamar las funciones para el cruce genetico, poner nuevos obstaculos y calcular la ruta.
         * Es la que se llama despues de cada iteración
         * @return
         */
        string play();

        /*!
         * addObstacle se encarga de añadir un nuevo obstaculo
         * @return
         */
        bool addObstacle();

        /*!
         * addToHistoricalArmy se encarga de añadir cada generación a la lista historica de gladiadores
         * @param army
         */
        void addToHistoricalArmy(List<Gladiator> army);

        /*!
         * sendGraphic se encarga de añadir las caracteristicas de todos los gladiadores a un json que es el que enviaremos
         * para que la interfaz realice el gráfico.
         * @return
         */
        string sendGraphic();

        /*!
         * addResistance añade las resistencias historicas
         * @param historicalArmy
         */
        void addResistance(List<Gladiator> historicalArmy);

        /*!
         * addUpperStrenght añade todas las fuerzas de tronco inferior historicas
         * @param historicalArmy
         */
        void addUpperStrenght(List<Gladiator> historicalArmy);

        /*!
         * addLowerStrenght añade todas las fuerzas de tronco inferior historicas
         * @param historicalArmy
         */
        void addLowerStrenght(List<Gladiator> historicalArmy);

        /*!
         * addEmotionalIntelligence añade todas las inteligencias emocionales historicas
         * @param historicalArmy
         */
        void addEmotionalIntelligence(List<Gladiator> historicalArmy);

        /*!
         * addPhysicalCondition añade todas las condiciones físicas historicas
         * @param historicalArmy
         */
        void addPhysicalCondition(List<Gladiator> historicalArmy);

        /*!
         * addAge añade todas las edades historicas
         * @param historicalArmy
         */
        void addAge(List<Gladiator> historicalArmy);

        /*!
         * addExpectedGenerations añade todas las expectedGenerations historicas
         * @param historicalArmy
         */
        void addExpectedGenerations(List<Gladiator> historicalArmy);

        /*!
         * addSurvivalProb añade todas las survivalProb historicas
         * @param historicalArmy
         */
        void addSurvivalProb(List<Gladiator> historicalArmy);

        /*!
         * addFitness añade todos los fitness historicos
         * @param historicalArmy
         */
        void addFitness(List<Gladiator> historicalArmy);

        /*!
         * addId añade todos los Id historicos
         * @param historicalArmy
         */
        void addId(List<Gladiator> historicalArmy);


};


#endif //A_GAME_H
