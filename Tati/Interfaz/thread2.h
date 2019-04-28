#ifndef THREAD2_H
#define THREAD2_H
#include <QThread>

class Thread2:public QThread
{
  Q_OBJECT
protected:
  void run();
public:
  Thread2();
};

#endif // THREAD2_H
