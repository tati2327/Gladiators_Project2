#ifndef MYPLAYER_H
#define MYPLAYER_H
#include <QGraphicsRectItem>
class MyPlayer:public QGraphicsRectItem{
public:
  void keyPressEvent(QKeyEvent *event);
};

#endif // MYPLAYER_H
