#include "tower/kaguyatower.h"
#include "bullet.h"
#include "game.h"

#include <QTimer>

extern Game *game;

KaguyaTower::KaguyaTower(QGraphicsItem *parent)
    : Tower(parent)
{
    damage = KAGUYA_DAMAGE;
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(aquire_target()));
    timer->start(1000);
}

void KaguyaTower::fire()
{
    Bullet *bullet = new Bullet(damage);
    Bullet *bulletL = new Bullet(damage);
    Bullet *bulletR = new Bullet(damage);

    bullet->setBulletPixmap(":/images/BulletBig9.png");
    bulletL->setBulletPixmap(":/images/BulletBig9.png");
    bulletR->setBulletPixmap(":/images/BulletBig9.png");


    bullet->setPos(x()+24, y()+32);
    bulletL->setPos(x()+24, y()+32);
    bulletR->setPos(x()+24, y()+32);

    QLineF ln(QPointF(x()+24, y()+32), attack_dest);
    int angle = -1 * ln.angle();

    bullet->setRotation(angle);
    bulletL->setRotation(angle+10);
    bulletR->setRotation(angle-10);

    game->scene->addItem(bullet);
    game->scene->addItem(bulletL);
    game->scene->addItem(bulletR);
}

void KaguyaTower::aquire_target()
{
    Tower::aquire_target();
}
