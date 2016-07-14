#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include <QMediaPlayer>

#include "mainrect.h"
#include "Value/rolestate.h"
#include "Value/score.h"

class Game: public QGraphicsView
{
public:
    Game(QWidget *parent = 0);

    QGraphicsScene *scene;
    MainRect *role;
    Score *score;
    RoleState *health;
};

#endif // GAME_H
