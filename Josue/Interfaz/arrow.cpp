#include "arrow.h"
#include <QPixelFormat>
#include <QTimer>
#include <qmath.h>
#include "myplayer.h"
#include "qlist.h"
#include "game.h"
#include <QGraphicsScene>
extern  Game* g;
extern bool status;
extern bool shoot;
extern int jiteration;
Arrow::Arrow(QGraphicsItem *parent)
{
  setPixmap(QPixmap(":images/SimpleArrow.png"));

  QTimer *move_timer = new QTimer(this);
  connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
  move_timer->start(10);
}

void Arrow::move(){
  QList<QGraphicsItem *> colliding_items = collidingItems();
  for(int i=0,n=colliding_items.size();i<n;i++){
      if(typeid(*(colliding_items[i]))==typeid (MyPlayer)){
          g->life_points->setPlainText(QString::number(g->player->life_points-1));
          g->player->life_points--;
          scene()->removeItem(this);
          if (g->player->life_points<=0){
              delete g->player;
              status=true;
              MyPlayer *p = new MyPlayer();
              g->player = p;
              g->scene->addItem(p);
              p->setPos(71,32);
              p->setFlag(QGraphicsItem::ItemIsFocusable);
              p->setFocus();
              g->cont=0;
              g->timer->stop();
              if (jiteration>=5){
                  g->timer->start(1000);
                }
              else{
                  g->timer->start(2000);
                }
              shoot=false;
              g->ID->setPlainText(QString(QString::number(0)));
              g->player->life_points=resis;
              g->resistance->setPlainText(QString(QString::number(0)));
              g->life_points->setPlainText(QString(QString::number(0)));
              g->age->setPlainText(QString(QString::number(0)));
              g->upper_stregth->setPlainText(QString(QString::number(0)));
              g->lower_stregth->setPlainText(QString(QString::number(0)));
              g->physical_condition->setPlainText(QString(QString::number(0)));
              g->expected_gen->setPlainText(QString(QString::number(0)));
              g->survival_prob->setPlainText(QString(QString::number(0)));
              g->time_in->setPlainText(QString(QString::number(0)));
            }
          delete this;
          return;
        }
   }
  if (pos().y()<0||pos().x()<0||pos().x()>g->scene->width()||pos().y()>g->scene->height()){
      delete  this;
      return;
    }
  int mov = 20;
  double cita = rotation();
  double dy = mov * qSin(qDegreesToRadians(cita));
  double dx = mov * cos(qDegreesToRadians(cita));

  setPos(x()+dx,y()+dy);
}
