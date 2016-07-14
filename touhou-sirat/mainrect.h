#ifndef MAINRECT_H
#define MAINRECT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QMediaPlayer>

class MainRect : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    MainRect(QGraphicsItem *parent = 0);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
public slots:
    void spawn();
    void shooting();
private:
    QMediaPlayer *bullet_sound;
    bool shoot_state;

    int move_state;
private slots:
    void move_still();
    void print_image(QString path, int flag);
};

#endif // MAINRECT_H
