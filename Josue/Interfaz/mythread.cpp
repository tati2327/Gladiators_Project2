#include "mythread.h"
#include <QtDebug>
#include <client.h>
#include <game.h>
#include <QApplication>
/*MyThread::MyThread()
{
  run();
}
*/
void MyThread::run(int argc, char *argv[]){

  hello(argc,argv);

}
MyThread::MyThread(int argc, char *argv[])
{
 a=argc;

 run(argc,argv);

}

int MyThread::hello(int argc,char *argv[])
{
  QApplication a(argc,argv);
  Game *g = new Game();
  g->displayMenu();
  return a.exec();
}
