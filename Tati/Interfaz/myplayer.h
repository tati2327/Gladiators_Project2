#ifndef MYPLAYER_H
#define MYPLAYER_H
#include <QObject>
#include <QGraphicsPixmapItem>
class MyPlayer:public QObject,public QGraphicsPixmapItem{
  Q_OBJECT
public:
  MyPlayer(QGraphicsItem * parent =0);
  void keyPressEvent(QKeyEvent *event);
  int life_points=100;
  int ID=10;
  int age=0;
  int survival_prob=0;
  int expected_gen=0;
  int emotional_intelligence=0;
  int upper_stregth=0;
  int lower_stregth=0;
  int resistance=0;
  int physical_condition=0;
};

#endif // MYPLAYER_H
