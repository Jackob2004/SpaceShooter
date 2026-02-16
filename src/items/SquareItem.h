#ifndef SPACESHOOTER_SQUAREITEM_H
#define SPACESHOOTER_SQUAREITEM_H
#include "Item.h"


class SquareItem : public Item {
public:
    SquareItem();

    bool processInput(Player& player) override;
};


#endif //SPACESHOOTER_SQUAREITEM_H