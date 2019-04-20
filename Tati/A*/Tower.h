#ifndef A_TOWER_H
#define A_TOWER_H

#include "List.h"

class Tower {
public:
    List<int> pos;
    int range = 2;
    int damage = 0;

    Tower();
    bool moveTower(int x, int y);
};


#endif //A_TOWER_H
