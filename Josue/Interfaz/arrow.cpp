#include "arrow.h"
#include <QPixelFormat>
#include <QTimer>
#include <qmath.h>
#include "myplayer.h"
#include "qlist.h"
#include "game.h"
#include <QGraphicsScene>
extern  Game* g;
Arrow::Arrow(QGraphicsItem *parent)
{
  setPixmap(QPixmap(":images/arrow.png"));

  QTimer *move_timer = new QTimer(this);
  connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
  move_timer->start(50);
}

void Arrow::move(){
  QList<QGraphicsItem *> colliding_items = collidingItems();
  for(int i=0,n=colliding_items.size();i<n;i++){
      if(typeid(*(colliding_items[i]))==typeid (MyPlayer)){
          g->life_points->setPlainText(QString::number(g->player->life_points-1));
          g->player->life_points--;
          scene()->removeItem(this);
          delete this;
          return;
        }
    }
  int mov = 30;
  double cita = rotation();
  double dy = mov * qSin(qDegreesToRadians(cita));
  double dx = mov * cos(qDegreesToRadians(cita));

  setPos(x()+dx,y()+dy);
}
