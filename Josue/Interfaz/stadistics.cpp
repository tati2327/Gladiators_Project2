#include "stadistics.h"
#include <QFont>

Stadistics::Stadistics(QGraphicsItem *parent)
{
  setPlainText(QString("hola"));
  setDefaultTextColor(Qt::white);
  setFont(QFont("times",35));
}
