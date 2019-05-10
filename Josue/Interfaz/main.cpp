#include <QApplication>
#include <game.h>
#include <QDebug>
#include <iostream>
#include <thread>
#include <unistd.h>
#include "client.h"
#include "json.h"
#include "list.h"
#include "string.h"
using namespace std;
Game *g;
int id;
int resis;
int jlower;
int jupper;
int jage;
int jexpec;
int jsurv;
int jphys;
string obs1;
string rute;
List<char> *movs;
bool poner=false;
bool status=true;
int jtime;
int jiteration;
bool shoot=false;
bool finished=false;

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

