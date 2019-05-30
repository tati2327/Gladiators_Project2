#ifndef A_FIELD_H
#define A_FIELD_H

#include "../List.h"

class Field {
    public:
        int f, g, h, i, j;/*!Los primeros 3 son el valor que va a tener cada campo al clacular la ruta
        * los últimos indican la posicion en el tablero*/
        bool inLine, inDiagonal, obstacle;/*!Ayuda a saber si lo que se tiene es una linea, diagonal o si el field es un
       *obstaculo*/
        string father;/*!indica la posición del padre*/
        List<Field*> neighbors;/*!Lista de vecinos del field*/

        Field();
        /*!
         * setInLine levanta una bandera para saber que el field esta inLine
         * @param inLine
         */
        void setInLine(bool inLine);

        /*!
         * setInDiagonal levanta una bandera para saber que el field esta inDiagonal
         * @param inDiagonal
         */
        void setInDiagonal(bool inDiagonal);

        /*!
         * addObstacle activa el booleano obstacle de field
         * @return
         */
        bool addObstacle();

        /*!
         * isObstacle retorna el obstaculo
         * @return
         */
        bool isObstacle();

        /*!
         * equal se usa para saber si un campo es igual a otro
         * @param object
         * @return
         */
        bool equal(Field object);

        /*!
         * deleteField es la misma función delete adaptada para borrar objetos de tipo campo
         * @param _node
         * @param _list
         */
        void deleteField(Field _node, List<Field>& _list);
};

#endif //A_FIELD_H
