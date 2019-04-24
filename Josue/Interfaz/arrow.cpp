#include "arrow.h"
#include <QPixelFormat>
#include <QTimer>
#include <qmath.h>
Arrow::Arrow(QGraphicsItem *parent)
{
  setPixmap(QPixmap(":images/arrow.png"));

  QTimer *move_timer = new QTimer(this);
  connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
  move_timer->start(50);
}

void Arrow::move(){
  int mov = 30;
  double cita = rotation();
  double dy = mov * qSin(qDegreesToRadians(cita));
  double dx = mov * cos(qDegreesToRadians(cita));

  setPos(x()+dx,y()+dy);
}
