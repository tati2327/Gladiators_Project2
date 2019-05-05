#include <QApplication>
#include <game.h>
#include <QDebug>
#include <iostream>
#include <thread>
#include <unistd.h>
#include "client.h"
#include "json.h"
#include "list.h"
using namespace std;
Game *g;
int id;
int resis;
int jage;
int jlower;
int jupper;
int jexpec;
int jsurv;
int jphys;
List<char> *obs;
List<char> *movs;

int juego(int argc, char *argv[]){
  QApplication a(argc,argv);
  //Game *g = new Game();
  g=new Game();
  g->displayMenu();
  return a.exec();
}

void cliente(){
  Client c;
  c.newClient();
}

int main(int argc, char *argv[])
{
  std::thread first (juego,argc,argv);
  std::thread second(cliente);
  first.join();
  second.join();


  return 0;
}

