#include "mainrect.h"
#include "enemy.h"
#include "Weapon/bullet.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QKeyEvent>

MainRect::MainRect(QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/marisa01.png"));
    bullet_sound = new QMediaPlayer(this);
    bullet_sound->setMedia(QUrl("qrc:/sounds/bullet.wav"));

    // init begin
    shoot_state = false;
    move_state = 0;
    // init end

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(shooting()));
    QTimer *move_timer = new QTimer(this);
    connect(move_timer, SIGNAL(timeout()), this, SLOT(move_still()));

    timer->start(100);
    move_timer->start(50);
}

void MainRect::shooting(){
    if(!shoot_state){
        return;
    }
    Bullet *bullet = new Bullet();
    scene()->addItem(bullet);
    bullet->setPos(x(), y());
    if(bullet_sound->state() == QMediaPlayer::PlayingState){
        bullet_sound->setPosition(0);
    }
    bullet_sound->play();
}

void MainRect::move_still()
{
    /*if(move_state & 0x20){
        setTransformOriginPoint(16, 24);
        setRotation(180);
        //set
    }*/
    bool right = false;
    switch(move_state & 0x00f0){
    case 0x00:
        switch(move_state & 0x000f){
        case 0x0:
            setPixmap(QPixmap(":/images/marisa01.png"));
            move_state &= 0xfff0;
            move_state |= 0x0001;
            break;
        case 0x1:
            setPixmap(QPixmap(":/images/marisa02.png"));
            move_state &= 0xfff0;
            move_state |= 0x0002;
            break;
        case 0x2:
            setPixmap(QPixmap(":/images/marisa03.png"));
            move_state &= 0xfff0;
            move_state |= 0x0003;
            break;
        case 0x3:
            setPixmap(QPixmap(":/images/marisa04.png"));
            move_state &= 0xfff0;
            break;
        }
        break;
    case 0x20:
        right = true;
    case 0x10:
        switch(move_state & 0x000f){
        case 0x0:
            print_image(":/images/marisa05.png", right);
            move_state &= 0xfff0;
            move_state |= 0x0001;
            break;
        case 0x1:
            print_image(":/images/marisa06.png", right);
            move_state &= 0xfff0;
            move_state |= 0x0002;
            break;
        case 0x2:
            print_image(":/images/marisa07.png", right);
            move_state &= 0xfff0;
            move_state |= 0x0003;
            break;
        case 0x3:
            print_image(":/images/marisa08.png", right);
            move_state &= 0xfff0;
            move_state |= 0x0004;
            break;
        case 0x4:
            print_image(":/images/marisa09.png", right);
            move_state &= 0xfff0;
            move_state |= 0x0005;
            break;
        case 0x5:
            print_image(":/images/marisa10.png", right);
            move_state &= 0xfff0;
            move_state |= 0x0006;
            break;
        case 0x6:
            print_image(":/images/marisa11.png", right);
            move_state &= 0xfff0;
            break;
        }
        break;
    }

    if(move_state & 0x10){
        if(pos().x() > -8){
            setPos(x()-10, y());
        }
    }
    else if(move_state & 0x20){
        if(pos().x() < 776){
            setPos(x()+10, y());
        }
    }

    if(move_state & 0x100){
        setPos(x(), y()-10);
    }
    else if(move_state & 0x200){
        setPos(x(), y()+10);
    }
}

void MainRect::print_image(QString path, int flag)
{
    bool hori = false;
    if(flag == 1){
        hori = true;
    }
    setPixmap(QPixmap::fromImage(QImage(path).mirrored(hori, false)));
}

void MainRect::keyPressEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat()){
        return;
    }
    switch(event->key()){
    case Qt::Key_Left:
        move_state &= 0xf0f;
        move_state |= 0x010;
        break;
    case Qt::Key_Right:
        move_state &= 0xf0f;
        move_state |= 0x020;
        break;
    case Qt::Key_Up:
        move_state &= 0x0ff;
        move_state |= 0x100;
        break;
    case Qt::Key_Down:
        move_state &= 0x0ff;
        move_state |= 0x200;
        break;

    case Qt::Key_Space:
        shoot_state = true;
        break;
    }
}

void MainRect::keyReleaseEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat()){
        return;
    }
    switch(event->key()){
    case Qt::Key_Left:
        if(move_state & 0x010){
            move_state &= 0xf0f;
        }
        break;
    case Qt::Key_Right:
        if(move_state & 0x020){
            move_state &= 0xf0f;
        }
        break;
    case Qt::Key_Up:
        if(move_state & 0x100){
            move_state &= 0x0ff;
        }
        break;
    case Qt::Key_Down:
        if(move_state & 0x200){
            move_state &= 0x0ff;
        }
        break;
    case Qt::Key_Space:
        shoot_state = false;
        break;
    }
}

void MainRect::spawn()
{
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}

