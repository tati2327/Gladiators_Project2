#ifndef A_TOWER_H
#define A_TOWER_H

#include "List.h"

class Tower {
    public:
    /*! Hacer que el gladeador se meta en una cueva cuando termine el nivel y entre a un nivel nuevo*/
        List<int> pos;
        int range = 2;
        int damage = 0;

        Tower();
        bool moveTower(int x, int y);
};


#endif //A_TOWER_H
