#include "game.h"

#include <QBrush>
#include <QImage>

Game::Game(QWidget *parent)
    : QGraphicsView(parent)
{
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);

    // background begin
    setBackgroundBrush(QBrush(QImage(":/images/bg1.png")));
    // background end

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);

    MainRect *role = new MainRect();
    role->setPos(400, 500);
    //role->setPos(view->width()/2, view->height()-role->rect().height())x;
    role->setFlag(QGraphicsItem::ItemIsFocusable);
    role->setFocus();
    scene->addItem(role);

    score = new Score();
    health = new RoleState();
    scene->addItem(score);
    health->setPos(health->x(), health->y()+25);
    scene->addItem(health);

    QTimer *timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), role, SLOT(spawn()));
    timer->start(2000);

    // BGM add begin
    QMediaPlayer *bgm = new QMediaPlayer(this);
    bgm->setMedia(QUrl("qrc:/sounds/bgmusic.mp3"));
    bgm->play();
    // BGM add end


    show();
}
