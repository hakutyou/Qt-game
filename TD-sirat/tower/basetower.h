#ifndef BASETOWER_H
#define BASETOWER_H

#include <QObject>

#include "tower/tower.h"

#define BASETOWER_DAMAGE 5

class BaseTower : public Tower
{
    Q_OBJECT
public:
    BaseTower(QGraphicsItem *parent = 0);
    void fire();
public slots:
    void aquire_target();
private:
    int damage;
};

#endif // BASETOWER_H
