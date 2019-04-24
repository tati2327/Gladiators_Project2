#include "tower.h"
#include <stdlib.h>
#include <QPolygonF>
#include <QVector>
#include <QPointF>
#include  <QDebug>
#include "arrow.h"
Tower::Tower(QGraphicsItem *parent):QGraphicsPixmapItem (){
   setPixmap(QPixmap(":/images/torre.png"));
   srand(time(NULL));
   int randwidth = rand()%10;
   int randheight = rand()%10;
   int posx=randwidth*66.5+71;
   int posy=randheight*64+32;
   setPos(posx,posy);
   //setRect(0,0,30,30);

   QVector<QPoint> points;
   points << QPoint(-1,-1) << QPoint(-1,2) << QPoint(3,2) << QPoint(3,- 1);


   int SCALE_FACTORX = 44;
   int SCALE_FACTORY = 60;
   for (size_t i =0,n=points.size();i<n;i++){
       points[i].rx()*=SCALE_FACTORX;
       points[i].ry()*=SCALE_FACTORY;
     }
   attack_area = new QGraphicsPolygonItem(QPolygonF(points),this);

}



