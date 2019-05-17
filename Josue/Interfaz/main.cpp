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
float jsurv;
int jphys;
int jem;
string obs1;
string rute;
List<char> *movs;
bool poner=false;
bool status=true;
int jtime;
int jiteration;
bool shoot=false;
bool finished=false;
List<int> gid;
List<int> gresistance;
List<int> physical;
List<float> survival;
List<int> expected;
List<int> aget;
List<int> uppers;
List<int> lowers;
List<int> emotional;
bool graph=false;
bool movet=false;
bool ya=false;


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

