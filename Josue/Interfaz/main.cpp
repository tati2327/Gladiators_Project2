#include <QApplication>
#include <game.h>
#include <QDebug>
#include <iostream>
#include <thread>
#include <unistd.h>
#include "client.h"

using namespace std;
Game *g;
Client c;
int juego(int argc, char *argv[]){
  QApplication a(argc,argv);
  //Game *g = new Game();
  g=new Game();
  g->displayMenu();
  return a.exec();
}

void cliente(){

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

