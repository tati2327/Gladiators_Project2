#include "myplayer.h"
#include <QDebug>
#include <QKeyEvent>
MyPlayer::MyPlayer(QGraphicsItem *parent):QGraphicsPixmapItem ()
{
  setPixmap(QPixmap(":/images/gladeador.png"));
}

void MyPlayer::keyPressEvent(QKeyEvent *event)
{
  if (event->key()==Qt::Key_Left){
      setPos(x()-66.5,y());
    }
  if (event->key()==Qt::Key_Right){
      setPos(x()+66.5,y());
    }
  if (event->key()==Qt::Key_Down){
      setPos(x(),y()+70);
    }
  if (event->key()==Qt::Key_Up){
      setPos(x(),y()-70);
    }
}
