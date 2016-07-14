#include "tower/basetowerbuild.h"
#include "tower/basetower.h"
#include "game.h"

extern Game *game;

BaseTowerBuild::BaseTowerBuild(QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/wriggle1.png"));
}

void BaseTowerBuild::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->tower){
        game->tower = new BaseTower();
        game->setCursor(QString(":/images/wriggle1.png"));
    }
}


