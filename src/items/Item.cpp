#include "Item.h"

Item::Item(const int uses) :
    usesLeft(uses) {
}

bool Item::processInput(Player& player) {
    usesLeft--;
    return usesLeft > 0;
}