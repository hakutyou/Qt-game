#ifndef ROLESTATE_H
#define ROLESTATE_H

#include <QGraphicsTextItem>

class RoleState : public QGraphicsTextItem
{
public:
    RoleState(QGraphicsTextItem *parent = 0);
    void descrease();
    int getHealth();
private:
    int health;
};

#endif // ROLESTATE_H
