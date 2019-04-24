#ifndef MYPLAYER_H
#define MYPLAYER_H
#include <QObject>
#include <QGraphicsPixmapItem>
class MyPlayer:public QObject,public QGraphicsPixmapItem{
  Q_OBJECT
public:
  MyPlayer(QGraphicsItem * parent =0);
  void keyPressEvent(QKeyEvent *event);
  int life_points=10;
  int ID, age, survival_prob, expected_gen, emotional_intelligence,upper_stregth,lower_stregth,resistance,physical_condition;
};

#endif // MYPLAYER_H
