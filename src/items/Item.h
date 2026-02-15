#ifndef SPACESHOOTER_ITEM_H
#define SPACESHOOTER_ITEM_H

class Player;

class Item {
public:
    explicit Item(int uses);

    virtual ~Item() = default;

    virtual bool processInput(Player& player);

private:
    int usesLeft;
};


#endif //SPACESHOOTER_ITEM_H