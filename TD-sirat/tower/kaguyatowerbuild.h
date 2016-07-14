#ifndef KAGUYATOWERBUILD_H
#define KAGUYATOWERBUILD_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class KaguyaTowerBuild : public QGraphicsPixmapItem
{
public:
    KaguyaTowerBuild(QGraphicsItem *parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // KAGUYATOWERBUILD_H
