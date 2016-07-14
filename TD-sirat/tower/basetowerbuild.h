#ifndef BASETOWERBUILD_H
#define BASETOWERBUILD_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BaseTowerBuild : public QGraphicsPixmapItem
{
public:
    BaseTowerBuild(QGraphicsItem *parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BASETOWERBUILD_H
