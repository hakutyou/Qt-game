#ifndef MYSTIATOWERBUILD_H
#define MYSTIATOWERBUILD_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class MystiaTowerBuild : public QGraphicsPixmapItem
{
public:
    MystiaTowerBuild(QGraphicsItem *parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MYSTIATOWERBUILD_H
