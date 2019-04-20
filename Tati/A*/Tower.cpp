#include "Tower.h"

Tower::Tower(){
    pos.add(0);
    pos.add(0);
}

/*! El booleano es para más adelante saber si ese obstaculo
 * se puede poner o no en esa posición*/
bool Tower::moveTower(int x, int y) {
    pos.getNode(0)->data = x;
    pos.getNode(1)->data = y;
    return true;
}