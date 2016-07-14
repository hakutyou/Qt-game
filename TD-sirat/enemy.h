#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QList>
#include <QPointF>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy(QList<QPointF> pointsToFollow, int healpoint, QGraphicsItem *parent = 0);
    void rotateToPoint(QPointF p);

    int attack(int val);
public slots:
    void move_forward();
private:
    QList<QPointF> points;
    QPointF dest;
    int point_index;

    int healpoint;
};

#endif // ENEMY_H
