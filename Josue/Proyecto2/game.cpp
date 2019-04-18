#include "game.h"
#include <QBrush>
#include <QImage>
#include "mainmenu.h"
#include "button.h"
Game::Game()
{
  scene=new QGraphicsScene();
  view = new QGraphicsView(scene);
  view->show();
  view->setFixedSize(550,550);


  scene->setSceneRect(0,0,550,550);

  view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}

void Game::displayMenu()
{
  //MainMenu *m = new MainMenu();
  QGraphicsTextItem *title = new QGraphicsTextItem(QString("Gladiators"));
  QFont font("comicsans",30);
  int posx = this->width()/2 - title->boundingRect().width()/2;
  int posy = 100;
  title->setPos(posx,posy);
  title->setFont(font);
  scene->addItem(title);
  Button * button = new Button(QString("Play"));
  int posbx = this->width()/2 - button->boundingRect().width()/2;
  int posby = 200;
  button->setPos(posbx,posby);
  connect(button,SIGNAL(clicked()),this,SLOT(start()));
  scene->addItem(button);

  Button * quitButton = new Button(QString("Quit"));
  int posqx = this->width()/2 - button->boundingRect().width()/2;
  int posqy = 300;
  quitButton->setPos(posqx,posqy);
  connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
  scene->addItem(quitButton);
}

void Game::start()
{
  scene->clear();
  player = new MyPlayer();

  player->setRect(0,0,30,30);

  scene->addItem(player);


  player->setFlag(QGraphicsItem::ItemIsFocusable);

  player->setFocus();


  player->setPos(view->width()-player->rect().width(),view->height()-player->rect().height());

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

