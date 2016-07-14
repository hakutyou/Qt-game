#include "enemy.h"

#include <QPixmap>
#include <QTimer>
#include <QtMath>

Enemy::Enemy(QList<QPointF> pointsToFollow, int healpoint, QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/images/Enemy11.png"));

    this->healpoint = healpoint;
    // move dests
    points = pointsToFollow;
    point_index = 0;
    dest = points[0];
    rotateToPoint(dest);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move_forward()));
    timer->start(150);
}

void Enemy::rotateToPoint(QPointF p)
{
    QLineF ln(pos(), p);
    setRotation(-1 * ln.angle());
}

int Enemy::attack(int val)
{
    return healpoint -= val;
}

void Enemy::move_forward()
{
    // rotate procedure begin
    QLineF ln(pos(), dest);
    if(ln.length() < 5){
        point_index++;
        if(point_index >= points.size()){
            return;
        }
        dest = points[point_index];
        rotateToPoint(dest);
    }
    // rotate procedure end

    int STEP_SIZE = 5;
    double theta = rotation();
    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy);
}
