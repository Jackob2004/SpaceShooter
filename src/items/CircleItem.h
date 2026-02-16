#ifndef SPACESHOOTER_CIRCLEITEM_H
#define SPACESHOOTER_CIRCLEITEM_H
#include "Item.h"


class CircleItem : public Item {
public:
    CircleItem();

    bool processInput(Player& player) override;
};

#endif //SPACESHOOTER_CIRCLEITEM_H