#include "game.h"
#include <QBrush>
#include <QImage>
#include "mainmenu.h"
#include "button.h"
#include <QDebug>
#include <tower.h>
#include <tower2.h>
#include <tower3.h>
#include <arrow.h>
#include <stdlib.h>

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

  Button * button = new Button(QString("Play"));
  double posbx = scene->width()/2 - button->boundingRect().width()/2;
  int posby = 200;
  button->setPos(posbx,posby);
  connect(button,SIGNAL(clicked()),this,SLOT(start()));
  scene->addItem(button);
  Button * quitButton = new Button(QString("Quit"));
  double posqx = scene->width()/2 - button->boundingRect().width()/2;
  int posqy = 300;



  quitButton->setPos(posqx,posqy);
  connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
  scene->addItem(quitButton);
}



void Game::start()
{
  scene->clear();

  player = new MyPlayer();



  scene->addItem(player);
  int posx = 71;
  int posy= 32;
  player->setPos(posx,posy);
  player->setFlag(QGraphicsItem::ItemIsFocusable);
  player->setFocus();

  life_points = new Stadistics();
  life_points->set(player->life_points,900,160,35);
  scene->addItem(life_points);

  ID = new Stadistics();
  ID->set(player->ID,920,223,20);
  scene->addItem(ID);

  age = new Stadistics();
  age->set(player->age,920,257,20);
  scene->addItem(age);

  survival_prob = new Stadistics();
  survival_prob->set(player->survival_prob,920,300,20);
  scene->addItem(survival_prob);

  expected_gen = new Stadistics();
  expected_gen->set(player->expected_gen,920,338,20);
  scene->addItem(expected_gen);

  emotional_intelligence  = new Stadistics();
  emotional_intelligence->set(player->emotional_intelligence,920,385,20);
  scene->addItem(emotional_intelligence);

  upper_stregth = new Stadistics();
  upper_stregth->set(player->upper_stregth,920,425,20);
  scene->addItem(upper_stregth);

  lower_stregth = new Stadistics();
  lower_stregth->set(player->lower_stregth,920,475,20);
  scene->addItem(lower_stregth);

  resistance = new Stadistics();
  resistance->set(player->resistance,920,515,20);
  scene->addItem(resistance);

  physical_condition = new Stadistics();
  physical_condition->set(player->physical_condition,920,555,20);
  scene->addItem(physical_condition);

  time_in = new Stadistics();
  time_in->set(0,880,43,35);
  time_in->setPlainText(QString("0000"));
  scene->addItem(time_in);

  scene->setBackgroundBrush(QBrush(QImage(":images/game.png")));

  timer = new QTimer();
  QObject::connect(timer,SIGNAL(timeout()),this,SLOT(spawn()));
  timer->start(1000);
}

void Game::close()
{
  view->close();
}

void Game::spawn()
{
  if (cont>=3){
      timer->stop();
      return;
    }
  srand(time(NULL));
  int t = (rand()%3)+0;
  if (t==0){
      Tower * tower = new Tower();
      scene->addItem(tower);
      cont++;
    }
  if (t==1){
      Tower2 * tower = new Tower2();
      scene->addItem(tower);
      cont++;
    }
  if (t==2){
      Tower3 * tower = new Tower3();
      scene->addItem(tower);
      cont++;
    }


}


