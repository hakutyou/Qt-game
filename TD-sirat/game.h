#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QPoint>
#include <QTimer>

#include "tower/tower.h"

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game();
    void setCursor(QString filename);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void createEnemies(int num);
    void createRoad();

    QGraphicsScene *scene;
    QGraphicsPixmapItem *cursor;
    Tower *tower;

    QTimer *spawnTimer;
    int enemiesSpawned;
    int maxNumberofEnemies;
    QList<QPointF>pointsToFollow;
public slots:
    void spawnEnemies();
};

#endif // GAME_H
