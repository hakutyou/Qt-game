#ifndef MYSTIATOWER_H
#define MYSTIATOWER_H

#include <QObject>

#include "tower/tower.h"

#define MYSTIA_DAMAGE 2

class MystiaTower : public Tower
{
    Q_OBJECT
public:
    MystiaTower(QGraphicsItem *parent = 0);
    void fire();
public slots:
    void aquire_target();
private:
    int damage;
};

#endif // MYSTIATOWER_H
