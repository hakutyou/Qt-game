#include "tower/tower.h"
#include "bullet.h"
#include "game.h"
#include "enemy.h"

#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QTimer>

extern Game *game;

Tower::Tower(QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent)
{
    QVector<QPointF> points;
    points << QPoint(1, 0) << QPoint(2, 0) << QPoint(3,1);
    points << QPoint(3, 2) << QPoint(2, 3) << QPoint(1,3);
    points << QPoint(0, 2) << QPoint(0, 1);

    int SCALE_FACTOR = 75;
    for(int i=0,n=points.size(); i<n; i++)
        points[i] *= SCALE_FACTOR;
    attack_area = new QGraphicsPolygonItem(QPolygonF(points), this);
    attack_area->setPen(QPen(Qt::DotLine));

    QPointF poly_center(1.5, 1.5);
    poly_center *= SCALE_FACTOR;
    poly_center = mapToScene(poly_center);
    QPointF tower_center(x()+24, y()+32);
    QLineF ln(poly_center, tower_center);
    attack_area->setPos(x()+ln.dx(), y()+ln.dy());

    attack_dest = QPointF(0, 0);
    has_target = false;
}

double Tower::distanceTo(QGraphicsItem *item)
{
    QLineF ln(pos(), item->pos());
    return ln.length();
}

void Tower::aquire_target()
{
    QList<QGraphicsItem *>colliding_items =
            attack_area->collidingItems();
    has_target = false;

    double closest_dist = 300;
    QPointF closest_pt = QPointF(0, 0);
    for(int i=0, n=colliding_items.size(); i<n; i++){
        Enemy *enemy = dynamic_cast<Enemy *>(colliding_items[i]);
        if(enemy){
            double tdist = distanceTo(colliding_items[i]);
            if(tdist < closest_dist){
                closest_dist = tdist;
                closest_pt = colliding_items[i]->pos();
                has_target = true;
            }
        }
    }
    if(has_target){
        attack_dest = closest_pt;
        fire();
    }
}
