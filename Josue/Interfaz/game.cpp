#include "game.h"
#include <QBrush>
#include <QImage>
#include "button.h"
#include <QDebug>
#include <tower.h>
#include <tower2.h>
#include <tower3.h>
#include <arrow.h>
#include <stdlib.h>
#include <iostream>
#include "string.h"
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

// Define the scope for your variables and functions
QT_CHARTS_USE_NAMESPACE


using namespace std;
extern int id;
extern int resis;
extern int jage;
extern int jlower;
extern int jupper;
extern int jexpec;
extern int jsurv;
extern int jphys;
extern bool status;
extern string obs1;
extern string rute;
extern bool poner;
extern int jiteration;
extern int jtime;
extern bool finished;
string backuprute;
int backuptime;

extern bool shoot;
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

void Game::putTowers()
{
  if (obs1=="a"){
    rute=backuprute;

    time_in->setPlainText(QString(QString::number(backuptime)+" ms"));
    }
  else {
      int t1x = int(obs1[0])-48;
      int t1y = int(obs1[1])-48;
      int t2x = int(obs1[2])-48;
      int t2y = int(obs1[3])-48;
      int t3x = int(obs1[4])-48;
      int t3y = int(obs1[5])-48;
      srand(time(NULL));
      int t1 =(rand()%10)+0;
      int t2 =(rand()%10)+0;
      int t3 =(rand()%10)+0;
      if((jiteration<=1 && jiteration<3)||jiteration==2){

          if (t1==0){
              Tower * tower = new Tower();
              tower->setPos(t1x*66.5+72,t1y*64+29);
              scene->addItem(tower);

            }
          if (t1>0 && t1<=3){
              Tower2 * tower = new Tower2();

              tower->setPos(t1x*66.5+72,t1y*64+29);
              scene->addItem(tower);
            }
          if (t1>3 && t1<=9){
              Tower3 * tower = new Tower3();

              tower->setPos(t1x*66.5+72,t1y*64+29);
              scene->addItem(tower);

            }
          if (t2==0){

              Tower * tower = new Tower();
              scene->addItem(tower);
              tower->setPos(t2x*66.5+72,t2y*64+29);
            }
          if (t2>0 && t2<=4){
              Tower2 * tower = new Tower2();
              scene->addItem(tower);
              tower->setPos(t2x*66.5+72,t2y*64+29);
            }
          if (t2>4 && t2<=9){
              Tower3 * tower = new Tower3();
              scene->addItem(tower);
              tower->setPos(t2x*66.5+72,t2y*64+29);
            }
          if (t3==0){
              Tower * tower = new Tower();
              scene->addItem(tower);
              tower->setPos(t3x*66.5+72,t3y*64+29);
            }
          if (t3>0 && t3<=4){
              Tower2 * tower = new Tower2();
              scene->addItem(tower);
              tower->setPos(t3x*66.5+72,t3y*64+29);
            }
          if (t3>4 && t3<=9){
              Tower3 * tower = new Tower3();
              scene->addItem(tower);
              tower->setPos(t3x*66.5+72,t3y*64+29);
            }
        }
      if(jiteration>=3 && jiteration<5){
          if (t1>=0 && t1<=2){
              Tower * tower = new Tower();
              tower->setPos(t1x*66.5+72,t1y*64+29);
              scene->addItem(tower);

            }
          if (t1>2 && t1<=6){
              Tower2 * tower = new Tower2();

              tower->setPos(t1x*66.5+72,t1y*64+29);
              scene->addItem(tower);
            }
          if (t1>6 && t1<=9){
              Tower3 * tower = new Tower3();

              tower->setPos(t1x*66.5+72,t1y*64+29);
              scene->addItem(tower);

            }
          if (t2>=0 && t2<=2){

              Tower * tower = new Tower();
              scene->addItem(tower);
              tower->setPos(t2x*66.5+72,t2y*64+29);
            }
          if (t2>2 && t2<=6){
              Tower2 * tower = new Tower2();
              scene->addItem(tower);
              tower->setPos(t2x*66.5+72,t2y*64+29);
            }
          if (t2>6 && t2<=9){
              Tower3 * tower = new Tower3();
              scene->addItem(tower);
              tower->setPos(t2x*66.5+72,t2y*64+29);
            }
          if (t3>=0 && t3<=2){
              Tower * tower = new Tower();
              scene->addItem(tower);
              tower->setPos(t3x*66.5+72,t3y*64+29);
            }
          if (t3>2 && t3<=6){
              Tower2 * tower = new Tower2();
              scene->addItem(tower);
              tower->setPos(t3x*66.5+72,t3y*64+29);
            }
          if (t3>6 && t3<=9){
              Tower3 * tower = new Tower3();
              scene->addItem(tower);
              tower->setPos(t3x*66.5+72,t3y*64+29);
            }
        }
      if(jiteration>=5){
          if (t1>=0 && t1<=6){
              Tower * tower = new Tower();
              tower->setPos(t1x*66.5+72,t1y*64+29);
              scene->addItem(tower);

            }
          if (t1>6 && t1<=8){
              Tower2 * tower = new Tower2();

              tower->setPos(t1x*66.5+72,t1y*64+29);
              scene->addItem(tower);
            }
          if (t1==9){
              Tower3 * tower = new Tower3();

              tower->setPos(t1x*66.5+72,t1y*64+29);
              scene->addItem(tower);

            }
          if (t2>=0 && t2<=6){

              Tower * tower = new Tower();
              scene->addItem(tower);
              tower->setPos(t2x*66.5+72,t2y*64+29);
            }
          if (t2>6 && t2<=8){
              Tower2 * tower = new Tower2();
              scene->addItem(tower);
              tower->setPos(t2x*66.5+72,t2y*64+29);
            }
          if (t2==9){
              Tower3 * tower = new Tower3();
              scene->addItem(tower);
              tower->setPos(t2x*66.5+72,t2y*64+29);
            }
          if (t3>=0 && t3<=6){
              Tower * tower = new Tower();
              scene->addItem(tower);
              tower->setPos(t3x*66.5+72,t3y*64+29);
            }
          if (t3>6 && t3<=8){
              Tower2 * tower = new Tower2();
              scene->addItem(tower);
              tower->setPos(t3x*66.5+72,t3y*64+29);
            }
          if (t3==9){
              Tower3 * tower = new Tower3();
              scene->addItem(tower);
              tower->setPos(t3x*66.5+72,t3y*64+29);
            }
        }
      backuprute=rute;
      backuptime = jtime;
        }




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

void Game::endgame()
{
  scene->clear();
  scene->setBackgroundBrush(QBrush(QImage(":images/inicio.png")));
  // Assign names to the set of bars used
         QBarSet *set0 = new QBarSet("Altuve");
         QBarSet *set1 = new QBarSet("Martinez");
         QBarSet *set2 = new QBarSet("Segura");
         QBarSet *set3 = new QBarSet("Simmons");
         QBarSet *set4 = new QBarSet("Trout");

         // Assign values for each bar
         *set0 << 283 << 341 << 313 << 338 << 346 << 335;
         *set1 << 250 << 315 << 282 << 307 << 303 << 330;
         *set2 << 294 << 246 << 257 << 319 << 300 << 325;
         *set3 << 248 << 244 << 265 << 281 << 278 << 313;
         *set4 << 323 << 287 << 299 << 315 << 306 << 313;

         // Add all sets of data to the chart as a whole
         // 1. Bar Chart
         QBarSeries *series = new QBarSeries();

         // 2. Stacked bar chart
         // QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();
         series->append(set0);
         series->append(set1);
         series->append(set2);
         series->append(set3);
         series->append(set4);

         // Used to define the bar chart to display, title
         // legend,
         QChart *chart = new QChart();

         // Add the chart
         chart->addSeries(series);

         // Set title
         chart->setTitle("Gladiators by Resistance");

         // Define starting animation
         // NoAnimation, GridAxisAnimations, SeriesAnimations
         chart->setAnimationOptions(QChart::AllAnimations);

         // Holds the category titles
         QStringList categories;
         categories << "2013" << "2014" << "2015" << "2016" << "2017" << "2018";

         // Adds categories to the axes
         QBarCategoryAxis *axis = new QBarCategoryAxis();
         axis->append(categories);
         chart->createDefaultAxes();

         // 1. Bar chart
         chart->setAxisX(axis, series);

         // 2. Stacked Bar chart
         // chart->setAxisY(axis, series);

         // Define where the legend is displayed
         chart->legend()->setVisible(true);
         chart->legend()->setAlignment(Qt::AlignBottom);

         // Used to display the chart
         QChartView *chartView = new QChartView(chart);
         chartView->setRenderHint(QPainter::Antialiasing);

         //view->close();
         chartView->show();



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
  ID->set(id,920,223,20);
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
  ID->setPlainText(QString(QString::number(id)));
  player->life_points=resis;
  resistance->setPlainText(QString(QString::number(resis)));
  life_points->setPlainText(QString(QString::number(resis)));
  age->setPlainText(QString(QString::number(jage)));
  upper_stregth->setPlainText(QString(QString::number(jupper)));
  lower_stregth->setPlainText(QString(QString::number(jlower)));
  physical_condition->setPlainText(QString(QString::number(jphys)));
  expected_gen->setPlainText(QString(QString::number(jexpec)));
  survival_prob->setPlainText(QString(QString::number(jsurv)));
  timer = new QTimer();
  QObject::connect(timer,SIGNAL(timeout()),this,SLOT(spawn()));
  timer->start(2000);




}

void Game::close()
{
  view->close();
}

void Game::spawn()
{
  if (poner){
      ID->setPlainText(QString(QString::number(id)));
      player->life_points=resis;
      resistance->setPlainText(QString(QString::number(resis)));
      life_points->setPlainText(QString(QString::number(resis)));
      age->setPlainText(QString(QString::number(jage)));
      upper_stregth->setPlainText(QString(QString::number(jupper)));
      lower_stregth->setPlainText(QString(QString::number(jlower)));
      physical_condition->setPlainText(QString(QString::number(jphys)));
      expected_gen->setPlainText(QString(QString::number(jexpec)));
      survival_prob->setPlainText(QString(QString::number(jsurv)));
      time_in->setPlainText(QString(QString::number(jtime)+" ms"));
      putTowers();
      poner=false;
    }
  if (cont<rute.size()){
      player->setPos((int(rute[cont])-48)*66.5+73,(int(rute[cont+1])-48)*64+29);
      cont=cont+2;
      if (cont>0){
          shoot=true;
        }

    }
  if (player->pos().x()>615 && player->pos().y()>598){
      finished = true;
      timer->stop();
      endgame();
}


//  if (cont>=3){
//      timer->stop();
//      return;
//    }
//  srand(time(NULL));
//  int t = (rand()%3)+0;
//  if (t==0){
//      Tower * tower = new Tower();
//      scene->addItem(tower);
//      cont++;
//    }
//  if (t==1){
//      Tower2 * tower = new Tower2();
//      scene->addItem(tower);
//      cont++;
//    }
//  if (t==2){
//      Tower3 * tower = new Tower3();
//      scene->addItem(tower);
//      cont++;
//    }


}


