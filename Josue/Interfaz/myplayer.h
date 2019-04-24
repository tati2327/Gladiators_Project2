#ifndef MYPLAYER_H
#define MYPLAYER_H
#include <QObject>
#include <QGraphicsPixmapItem>
class MyPlayer:public QObject,public QGraphicsPixmapItem{
  Q_OBJECT
public:
  MyPlayer(QGraphicsItem * parent =0);
  void keyPressEvent(QKeyEvent *event);
};

#endif // MYPLAYER_H
