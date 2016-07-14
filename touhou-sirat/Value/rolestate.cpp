#include "rolestate.h"
#include <QFont>

RoleState::RoleState(QGraphicsTextItem *parent)
    : QGraphicsTextItem(parent)
{
    health = 3;
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));
}

void RoleState::descrease(){
    health--;
    setPlainText(QString("Health: ") + QString::number(health));
}

int RoleState::getHealth(){
    return health;
}

