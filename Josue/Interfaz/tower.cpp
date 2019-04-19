#include "tower.h"
#include <stdlib.h>
#include <QPolygonF>
#include <QVector>
#include <QPointF>
Tower::Tower(QGraphicsItem *parent):QGraphicsPixmapItem (){
   setPixmap(QPixmap(":/images/torre.png"));
   srand(time(NULL));
   int randwidth = rand()%10;
   int randheight = rand()%10;

   setPos(randwidth*66.5+71,randheight*64+32);
   //setRect(0,0,30,30);

   QVector<QPoint> points;
   points << QPoint(0,0) << QPoint(3,0) << QPoint(3,3) << QPoint(0,3);
   int SCALE_FACTOR = 40;
   for (size_t i =0,n=points.size();i<n;i++){
       points[i]*=SCALE_FACTOR;
     }
   attack_area = new QGraphicsPolygonItem(QPolygonF(points),this);

   //QPointF poly_center(1.5,1.5);
   //poly_center *=SCALE_FACTOR;
   //poly_center = mapToScene(poly_center);
   //QPointF tower_center(x()+44,y()+44);
   //QLineF ln(poly_center,tower_center);
   //attack_area->setPos(x()+ln.dx(),y()+ln.dy());
}
