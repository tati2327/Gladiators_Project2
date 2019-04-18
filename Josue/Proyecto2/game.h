#ifndef GAME_H
#define GAME_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <myplayer.h>
#include <QTimer>
#include "myplayer.h"
#include <QObject>
#include <QWidget>
#include <tower.h>
class Game:public QGraphicsView
{
  Q_OBJECT
public:
  Game();
  QGraphicsView *view;
  QGraphicsScene *scene;
  MyPlayer *player;
  void displayMenu();


  void movement(int movement);
public slots:
  void spawn();
  void start();
  void close();
};

#endif // GAME_H
