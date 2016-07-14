#include "tower/mystiatowerbuild.h"
#include "tower/mystiatower.h"
#include "game.h"

extern Game *game;

MystiaTowerBuild::MystiaTowerBuild(QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/mystia1.png"));
}

void MystiaTowerBuild::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->tower){
        game->tower = new MystiaTower();
        game->setCursor(QString(":/images/mystia1.png"));
    }
}
