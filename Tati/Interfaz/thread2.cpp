#include "thread2.h"
#include "client.h"
#include "QDebug"
Thread2::Thread2()
{
  run();
}


void Thread2::run()
{
  int a=100;
  while(a!=0){
      qDebug()<<a;
      a--;
    }
  Client c;
  c.newClient();
}

