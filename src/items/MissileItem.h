#ifndef SPACESHOOTER_MISSILEITEM_H
#define SPACESHOOTER_MISSILEITEM_H
#include "Item.h"


class MissileItem : public Item {
public:
    MissileItem();

    bool processInput(Player& player) override;
};


#endif //SPACESHOOTER_MISSILEITEM_H