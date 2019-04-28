#include "myplayer.h"
#include <QDebug>
#include <QKeyEvent>
MyPlayer::MyPlayer(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem ()
{
  setPixmap(QPixmap(":/images/gladeador.png"));
}

void MyPlayer::keyPressEvent(QKeyEvent *event)
{
  if (event->key()==Qt::Key_Left){
      setPos(x()-67,y());
    }
  if (event->key()==Qt::Key_Right){
      setPos(x()+67,y());
    }
  if (event->key()==Qt::Key_Down){
      setPos(x(),y()+63);
    }
  if (event->key()==Qt::Key_Up){
      setPos(x(),y()-63);
    }
}
