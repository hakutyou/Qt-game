#include "bullet.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QMediaPlayer>

#include "game.h"
#include "enemy.h"

extern Game *game;
static QMediaPlayer *boom_sound = new QMediaPlayer();

Bullet::Bullet()
{
    setPixmap(QPixmap(":/images/bullet-marisa.png"));

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(10);
}

Bullet::~Bullet()
{
    ;
}

void Bullet::move()
{
    // collides check begin
    QList<QGraphicsItem *>colliding_items = collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; i++){
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){
            game->score->increase();

            boom_sound->setMedia(QUrl("qrc:/sounds/boom.wav"));
            boom_sound->setPosition(0);
            boom_sound->play();

            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    // collides check end
    setPos(x(), y()-10);
    if(pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
    return;
}
