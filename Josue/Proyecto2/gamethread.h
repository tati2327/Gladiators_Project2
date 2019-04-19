#ifndef GAMETHREAD_H
#define GAMETHREAD_H
#include <QThread>

class GameThread: public QThread
{
  Q_OBJECT
protected:
  void run();
public:
  GameThread();
};

#endif // GAMETHREAD_H
