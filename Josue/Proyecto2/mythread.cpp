#include "mythread.h"
#include <QtDebug>
#include <client.h>
MyThread::MyThread()
{
  run();
}
void MyThread::run(){
  int a=100;
  while(a!=0){
      qDebug()<<a;
      a--;
    }
  Client c;
  c.newClient();
}
