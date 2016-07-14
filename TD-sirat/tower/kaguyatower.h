#ifndef KAGUYATOWER_H
#define KAGUYATOWER_H

#include <QObject>

#include "tower/tower.h"

#define KAGUYA_DAMAGE 10

class KaguyaTower : public Tower
{
    Q_OBJECT
public:
    KaguyaTower(QGraphicsItem *parent = 0);
    void fire();
public slots:
    void aquire_target();
private:
    int damage;
};

#endif // KAGUYATOWER_H
