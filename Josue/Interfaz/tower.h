#ifndef TOWER_H
#define TOWER_H
#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
class Tower: public QGraphicsPixmapItem
{
public:
  Tower(QGraphicsItem * parent =0);

private:
  QGraphicsPolygonItem *attack_area;

};


#endif // TOWER_H
