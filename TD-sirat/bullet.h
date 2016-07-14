#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(int attackpoint, QGraphicsItem *parent = 0);
    void setBulletPixmap(QString filepath);
public slots:
    void move();

    double getMaxRange();
    double getDistanceTravelled();
    void setMaxRange(double range);
    void setDistanceTravelled(double dist);
private:
    double maxRange;
    double distanceTravelled;

    int attackpoint;
};

#endif // BULLET_H
