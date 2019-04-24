  #include "stadistics.h"
#include <QFont>

Stadistics::Stadistics(QGraphicsItem *parent)
{
  setDefaultTextColor(Qt::white);
}
void Stadistics::set(int player,int x, int y, int size)
{
  this->setPlainText(QString::number(player));
  this->setPos(x,y);
  setFont(QFont("times",size));
}
