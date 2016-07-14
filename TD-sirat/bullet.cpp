#include "bullet.h"
#include "enemy.h"

#include <QGraphicsScene>
#include <QPixmap>
#include <QTimer>
#include <QtMath>

Bullet::Bullet(int attackpoint, QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent)
{
    QTimer *move_timer = new QTimer(this);
    connect(move_timer, SIGNAL(timeout()), this, SLOT(move()));
    move_timer->start(50);

    // init
    this->attackpoint = attackpoint;
    maxRange = 100;
    distanceTravelled = 0;
}

void Bullet::setBulletPixmap(QString filepath){
    setPixmap(QPixmap(filepath));
}

void Bullet::move()
{
    // colliding check begin
    QList<QGraphicsItem *>colliding_items = collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; i++){
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){
            if((((Enemy *)colliding_items[i])->attack(attackpoint)) < 0){
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
            }
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    // colliding check end

    int STEP_SIZE = 30;
    double theta = rotation();
    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy);
}

double Bullet::getMaxRange()
{
    return maxRange;
}

double Bullet::getDistanceTravelled()
{
    return distanceTravelled;
}

void Bullet::setMaxRange(double range)
{
    maxRange = range;
}

void Bullet::setDistanceTravelled(double dist)
{
    distanceTravelled = dist;
}
