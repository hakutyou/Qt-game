#include "enemy.h"

#include <QTimer>
#include <QGraphicsScene>

#include "game.h"

extern Game *game;

Enemy::Enemy()
{
    setPixmap(QPixmap(":/images/enemy-part11.png"));
    int rnum = rand() % 700;
    setPos(rnum, 0);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Enemy::move(){
    setPos(x(), y()+5);
    if(pos().y() > 500){
        game->health->descrease();
        delete this;
        return;
    }
}
