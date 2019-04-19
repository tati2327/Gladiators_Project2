#include "game.h"
#include <QBrush>
#include <QImage>
#include "mainmenu.h"
#include "button.h"
#include <QDebug>
Game::Game()
{
  scene=new QGraphicsScene();
  view = new QGraphicsView(scene);

  scene->setBackgroundBrush(QBrush(QImage(":images/inicio.png")));
  view->show();
  view->setFixedSize(1050,700);


  scene->setSceneRect(0,0,1050,700);

  view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}

void Game::displayMenu()
{
  //MainMenu *m = new MainMenu();
  //QGraphicsTextItem *title = new QGraphicsTextItem(QString("Gladiators"));
  //QFont font("comicsans",30);
  //int posx = scene->width()/2-title->boundingRect().width()-title->boundingRect().width()*0.3;
  //int posy = 100;
  //title->setPos(posx,posy);
  //title->setFont(font);
  //scene->addItem(title);
  Button * button = new Button(QString("Play"));
  int posbx = scene->width()/2 - button->boundingRect().width()/2;
  int posby = 200;
  button->setPos(posbx,posby);
  connect(button,SIGNAL(clicked()),this,SLOT(start()));
  scene->addItem(button);
  Button * quitButton = new Button(QString("Quit"));
  int posqx = scene->width()/2 - button->boundingRect().width()/2;
  int posqy = 300;
  quitButton->setPos(posqx,posqy);
  connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
  scene->addItem(quitButton);
}

void Game::start()
{
  scene->clear();

  player = new MyPlayer();

  scene->setBackgroundBrush(QBrush(QImage(":images/game.png")));


  scene->addItem(player);
  int posx = 71;
  int posy= 32;
  player->setPos(posx,posy);
  player->setFlag(QGraphicsItem::ItemIsFocusable);

  player->setFocus();


  QTimer *timer = new QTimer();
  QObject::connect(timer,SIGNAL(timeout()),this,SLOT(spawn()));
  timer->start(4000);
}

void Game::close()
{
  view->close();
}

void Game::spawn()
{
  Tower * tower = new Tower();
  scene->addItem(tower);
}
void Game::movement(int movement){
  if (movement==1)player->setPos(player->x()+10,player->y());
  if (movement==2)player->setPos(player->x()-10,player->y());
  if (movement==3)player->setPos(player->x(),player->y()+10);
  if (movement==4)player->setPos(player->x(),player->y()-10);
                }

