#include "tower/basetower.h"
#include "bullet.h"
#include "game.h"

#include <QTimer>

extern Game *game;

BaseTower::BaseTower(QGraphicsItem *parent)
    : Tower(parent)
{
    damage = BASETOWER_DAMAGE;
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(aquire_target()));
    timer->start(1000);
}

void BaseTower::fire()
{
    Bullet *bullet = new Bullet(damage);
    bullet->setBulletPixmap(":/images/BulletSmall1.png");
    bullet->setPos(x()+24, y()+32);

    QLineF ln(QPointF(x()+24, y()+32), attack_dest);
    int angle = -1 * ln.angle();

    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}

void BaseTower::aquire_target()
{
    Tower::aquire_target();
}
