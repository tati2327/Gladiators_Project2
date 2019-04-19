#include <QApplication>
#include <gamethread.h>
#include <mythread.h>
#include <game.h>
#include <QDebug>
int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  //MyThread  *m = new MyThread();
  //m->start();
  //m->wait();
  qDebug() << "Fiooooooo";
  Game *g = new Game();

  g->displayMenu();
  return a.exec();
}

