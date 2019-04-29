#ifndef GAME_H
#define GAME_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <myplayer.h>
#include <QTimer>
#include "myplayer.h"
#include <QObject>
#include <QWidget>

#include "stadistics.h"
#include<QKeyEvent>
class Game:public QGraphicsView
{
  Q_OBJECT
public:
  Game();
  QGraphicsView *view;
  QGraphicsScene *scene;
  MyPlayer *player;
  Stadistics *life_points;
  Stadistics* ID, *age, *survival_prob, *expected_gen, *emotional_intelligence,*upper_stregth,*lower_stregth,*resistance,*physical_condition,*time_in;
  QTimer *timer;
  int cont=0;
  void displayMenu();
  void endgame();
public slots:
  void spawn();
  void start();
  void close();
};

#endif // GAME_H
