#include "tower.h"
#include <stdlib.h>
Tower::Tower():QGraphicsRectItem (){
   int randwidth = rand()%700;
   int randheight = rand()%500;

   setPos(randwidth,randheight);
   setRect(0,0,100,50);
}
