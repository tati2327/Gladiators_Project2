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
#include "list.h"

// Define the scope for your variables and functions
QT_CHARTS_USE_NAMESPACE


using namespace std;
extern int id;
extern int resis;
extern int jage;
extern int jlower;
extern int jupper;
extern int jexpec;
extern float jsurv;
extern int jphys;
extern int jem;
extern bool status;
extern string obs1;
extern string rute;
extern bool poner;
extern int jiteration;
extern int jtime;
extern bool finished;
extern List<int> gid;
extern List<int> gresistance;
extern List<float> survival;
extern List<int> physical;
extern List<int> expected;
extern List<int> aget;
extern List<int> uppers;
extern List<int> lowers;
extern List<int> emotional;
extern bool graph;
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
          if (t1>=0 && t1<=5){
              Tower * tower = new Tower();
              tower->setPos(t1x*66.5+72,t1y*64+29);
              scene->addItem(tower);

            }
          if (t1>5 && t1<=7){
              Tower2 * tower = new Tower2();

              tower->setPos(t1x*66.5+72,t1y*64+29);
              scene->addItem(tower);
            }
          if (t1>7 && t1<=9){
              Tower3 * tower = new Tower3();

              tower->setPos(t1x*66.5+72,t1y*64+29);
              scene->addItem(tower);

            }
          if (t2>=0 && t2<=5){

              Tower * tower = new Tower();
              scene->addItem(tower);
              tower->setPos(t2x*66.5+72,t2y*64+29);
            }
          if (t2>5 && t2<=7){
              Tower2 * tower = new Tower2();
              scene->addItem(tower);
              tower->setPos(t2x*66.5+72,t2y*64+29);
            }
          if (t2>7 && t2<=9){
              Tower3 * tower = new Tower3();
              scene->addItem(tower);
              tower->setPos(t2x*66.5+72,t2y*64+29);
            }
          if (t3>=0 && t3<=5){
              Tower * tower = new Tower();
              scene->addItem(tower);
              tower->setPos(t3x*66.5+72,t3y*64+29);
            }
          if (t3>5 && t3<=7){
              Tower2 * tower = new Tower2();
              scene->addItem(tower);
              tower->setPos(t3x*66.5+72,t3y*64+29);
            }
          if (t3>7 && t3<=9){
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
  while(!graph){

    }
  // Assign names to the set of bars used
  QBarSeries *series = new QBarSeries();
  for(int i =0;i<gid.size();i++){
      QBarSet *set = new QBarSet(QString::number(gid.getData(i)));
      *set << gresistance.getData(i);
      series->append(set);
    }

   QChart *chart = new QChart();

     chart->addSeries(series);

     chart->setTitle("Gladiators by Resistance");

     chart->setAnimationOptions(QChart::AllAnimations);

     QStringList categories;
     categories<<"ID";
     QBarCategoryAxis *axis = new QBarCategoryAxis();
     axis->append(categories);
     chart->createDefaultAxes();

     chart->legend()->setVisible(true);
     chart->legend()->setAlignment(Qt::AlignBottom);


     QChartView *chartView = new QChartView(chart);
     chartView->setRenderHint(QPainter::Antialiasing);

     chartView->show();

     QBarSeries *series2 = new QBarSeries();
     for(int i =0;i<gid.size();i++){
         QBarSet *set = new QBarSet(QString::number(gid.getData(i)));
         *set << survival.getData(i);
         series2->append(set);
       }

      QChart *chart2 = new QChart();


        chart2->addSeries(series2);

        chart2->setTitle("Gladiators by Survival Probability");

        chart2->setAnimationOptions(QChart::AllAnimations);

        QStringList categories2;
        categories2<<"ID";

        QBarCategoryAxis *axis2 = new QBarCategoryAxis();
        axis2->append(categories);
        chart2->createDefaultAxes();


        chart2->legend()->setVisible(true);
        chart2->legend()->setAlignment(Qt::AlignBottom);


        QChartView *chartView2 = new QChartView(chart2);
        chartView2->setRenderHint(QPainter::Antialiasing);


        chartView2->show();

        QBarSeries *series3 = new QBarSeries();
        for(int i =0;i<gid.size();i++){
            QBarSet *set = new QBarSet(QString::number(gid.getData(i)));
            *set << physical.getData(i);
            series3->append(set);
          }
        QChart *chart3 = new QChart();

          chart3->addSeries(series3);

          chart3->setTitle("Gladiators by Physical Condition");

          chart3->setAnimationOptions(QChart::AllAnimations);

          QStringList categories3;
          categories3<<"ID";

          QBarCategoryAxis *axis3 = new QBarCategoryAxis();
          axis3->append(categories);
          chart3->createDefaultAxes();


          chart3->legend()->setVisible(true);
          chart3->legend()->setAlignment(Qt::AlignBottom);

          QChartView *chartView3 = new QChartView(chart3);
          chartView3->setRenderHint(QPainter::Antialiasing);

          chartView3->show();

          QBarSeries *series4 = new QBarSeries();
          for(int i =0;i<gid.size();i++){
              QBarSet *set = new QBarSet(QString::number(gid.getData(i)));
              *set << emotional.getData(i);
              series4->append(set);
            }
          QChart *chart4 = new QChart();

            chart4->addSeries(series4);

            chart4->setTitle("Gladiators by Emotional Intelligence");

            chart4->setAnimationOptions(QChart::AllAnimations);

            QStringList categories4;
            categories4<<"ID";

            QBarCategoryAxis *axis4 = new QBarCategoryAxis();
            axis4->append(categories);
            chart4->createDefaultAxes();


            chart4->legend()->setVisible(true);
            chart4->legend()->setAlignment(Qt::AlignBottom);

            QChartView *chartView4 = new QChartView(chart4);
            chartView4->setRenderHint(QPainter::Antialiasing);

            chartView4->show();

            QBarSeries *series5 = new QBarSeries();
            for(int i =0;i<gid.size();i++){
                QBarSet *set = new QBarSet(QString::number(gid.getData(i)));
                *set << uppers.getData(i);
                series5->append(set);
              }
            QChart *chart5 = new QChart();

              chart5->addSeries(series3);

              chart5->setTitle("Gladiators by Upper Strenght");

              chart5->setAnimationOptions(QChart::AllAnimations);

              QStringList categories5;
              categories3<<"ID";

              QBarCategoryAxis *axis5 = new QBarCategoryAxis();
              axis5->append(categories);
              chart5->createDefaultAxes();


              chart5->legend()->setVisible(true);
              chart5->legend()->setAlignment(Qt::AlignBottom);

              QChartView *chartView5 = new QChartView(chart5);
              chartView5->setRenderHint(QPainter::Antialiasing);

              chartView5->show();

              QBarSeries *series6 = new QBarSeries();
              for(int i =0;i<gid.size();i++){
                  QBarSet *set = new QBarSet(QString::number(gid.getData(i)));
                  *set << lowers.getData(i);
                  series6->append(set);
                }
              QChart *chart6 = new QChart();

                chart6->addSeries(series3);

                chart6->setTitle("Gladiators by Lower Strenght");

                chart6->setAnimationOptions(QChart::AllAnimations);

                QStringList categories6;
                categories6<<"ID";

                QBarCategoryAxis *axis6 = new QBarCategoryAxis();
                axis6->append(categories);
                chart6->createDefaultAxes();


                chart6->legend()->setVisible(true);
                chart6->legend()->setAlignment(Qt::AlignBottom);

                QChartView *chartView6 = new QChartView(chart6);
                chartView6->setRenderHint(QPainter::Antialiasing);

                chartView6->show();

                QBarSeries *series7 = new QBarSeries();
                for(int i =0;i<gid.size();i++){
                    QBarSet *set = new QBarSet(QString::number(gid.getData(i)));
                    *set << aget.getData(i);
                    series7->append(set);
                  }
                QChart *chart7 = new QChart();

                  chart7->addSeries(series7);

                  chart7->setTitle("Gladiators by Age");

                  chart7->setAnimationOptions(QChart::AllAnimations);

                  QStringList categories7;
                  categories7<<"ID";

                  QBarCategoryAxis *axis7 = new QBarCategoryAxis();
                  axis7->append(categories);
                  chart7->createDefaultAxes();


                  chart7->legend()->setVisible(true);
                  chart7->legend()->setAlignment(Qt::AlignBottom);

                  QChartView *chartView7 = new QChartView(chart7);
                  chartView7->setRenderHint(QPainter::Antialiasing);

                  chartView7->show();

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
  emotional_intelligence->setPlainText(QString(QString::number(jem)));
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
      survival_prob->setPlainText(QString(QString::number(jsurv)+QString("%")));
      time_in->setPlainText(QString(QString::number(jtime)+" ms"));
      emotional_intelligence->setPlainText(QString(QString::number(jem)));
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


