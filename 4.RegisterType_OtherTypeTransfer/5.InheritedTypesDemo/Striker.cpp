#include "Striker.h"
#include <QDebug>

Striker::Striker(QObject *parent) : Player(parent)
{

}

void Striker::play()
{
    qDebug() << name() << " is playing";
}

void Striker::strike()
{
    qDebug() << name() << " is striking";
}
