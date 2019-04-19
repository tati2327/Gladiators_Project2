#include "mainmenu.h"

MainMenu::MainMenu()
{
  scene = new QGraphicsScene();

  QGraphicsView *view = new QGraphicsView(scene);

  view->show();
  view->setFixedSize(550,550);

  scene->setSceneRect(0,0,550,550);

  view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}
