#include "game.h"
#include "bullet.h"
#include "enemy.h"
#include "tower/basetower.h"
#include "tower/basetowerbuild.h"
#include "tower/mystiatower.h"
#include "tower/mystiatowerbuild.h"
#include "tower/kaguyatower.h"
#include "tower/kaguyatowerbuild.h"

#include <QGraphicsLineItem>

Game::Game()
    : QGraphicsView()
{
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 798, 598);
    setScene(scene);

    setFixedSize(800, 600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    cursor = nullptr;
    tower = nullptr;
    setMouseTracking(true);

    // init begin(tower, enemy)
    //BaseTower *bt = new BaseTower();
    //bt->setPos(250, 250);
    //scene->addItem(bt);
    //Enemy *enemy = new Enemy();
    //scene->addItem(enemy);
    spawnTimer = new QTimer(this);
    enemiesSpawned = 0;
    maxNumberofEnemies = 0;
    pointsToFollow << QPointF(800, 0) << QPointF(450, 450) << QPointF(0, 600);
    createEnemies(5);

    // road create
    createRoad();
    // init end

    BaseTowerBuild *icon_base = new BaseTowerBuild();
    MystiaTowerBuild *icon_myst = new MystiaTowerBuild();
    KaguyaTowerBuild *icon_kaguya = new KaguyaTowerBuild();

    icon_myst->setPos(x(), y()+64);
    icon_kaguya->setPos(x(), y()+128);
    scene->addItem(icon_base);
    scene->addItem(icon_myst);
    scene->addItem(icon_kaguya);
}

void Game::setCursor(QString filename)
{
    if(cursor){
        scene->removeItem(cursor);
        delete cursor;
    }

    cursor = new QGraphicsPixmapItem();
    cursor->setPixmap(QPixmap(filename));
    scene->addItem(cursor);
}

void Game::mouseMoveEvent(QMouseEvent *event)
{
    if(cursor){
        cursor->setPos(event->pos());
    }
}

void Game::mousePressEvent(QMouseEvent *event)
{
    if(tower){
        QList<QGraphicsItem *>items = cursor->collidingItems();
        for(int i=0,n=items.size(); i<n; i++){
            if(dynamic_cast<Tower *>(items[i]))
                return;
        }

        scene->addItem(tower);
        tower->setPos(event->pos());
        cursor = nullptr;
        tower = nullptr;
    }
    else{
        QGraphicsView::mousePressEvent(event);
    }
}

void Game::createEnemies(int num)
{
    enemiesSpawned = 0;
    maxNumberofEnemies = num;

    connect(spawnTimer, SIGNAL(timeout()), this, SLOT(spawnEnemies()));
    spawnTimer->start(1000);
}

void Game::createRoad()
{
    for(int i=0, n=pointsToFollow.size()-1; i<n; i++){
        QLineF ln(pointsToFollow[i], pointsToFollow[i+1]);
        QGraphicsLineItem *lnitem = new QGraphicsLineItem(ln);

        QPen pen;
        pen.setWidth(15);
        pen.setColor(Qt::darkGray);

        lnitem->setPen(pen);
        scene->addItem(lnitem);
    }
}

void Game::spawnEnemies()
{
    Enemy *enemy = new Enemy(pointsToFollow, 10);
    enemy->setPos(pointsToFollow[0]);
    scene->addItem(enemy);
    enemiesSpawned++;

    if(enemiesSpawned >= maxNumberofEnemies){
        spawnTimer->disconnect();

    }
}


