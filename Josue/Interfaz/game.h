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
  void displayMenu();
  Stadistics *life_points;

  void movement(int movement);
public slots:

  void spawn();
  void start();
  void close();
};

#endif // GAME_H
