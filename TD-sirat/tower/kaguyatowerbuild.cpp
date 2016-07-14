#include "tower/kaguyatowerbuild.h"
#include "tower/kaguyatower.h"
#include "game.h"

extern Game *game;

KaguyaTowerBuild::KaguyaTowerBuild(QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/kaguya1.png"));
}

void KaguyaTowerBuild::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->tower){
        game->tower = new KaguyaTower();
        game->setCursor(QString(":/images/kaguya1.png"));
    }
}
