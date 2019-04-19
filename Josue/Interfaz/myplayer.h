#ifndef MYPLAYER_H
#define MYPLAYER_H
#include <QGraphicsPixmapItem>
class MyPlayer:public QGraphicsPixmapItem{

public:
  MyPlayer(QGraphicsItem * parent =0);
  void keyPressEvent(QKeyEvent *event);
};

#endif // MYPLAYER_H
