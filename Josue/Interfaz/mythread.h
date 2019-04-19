#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>

class MyThread: public QThread
{
  Q_OBJECT
protected:
  void run();
public:
  MyThread();
};

#endif // MYTHREAD_H
