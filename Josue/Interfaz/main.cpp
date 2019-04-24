#include <QApplication>
#include <gamethread.h>
#include <mythread.h>
#include <game.h>
#include <QDebug>
#include <thread2.h>
#include <iostream>
#include <thread>
#include <unistd.h>
#include "client.h"

using namespace std;
Game *g;
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

