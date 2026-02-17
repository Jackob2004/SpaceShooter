#include "HeldItemDisplay.h"

#include "components/SpriteRenderer.h"

HeldItemDisplay::HeldItemDisplay() :
    Display({10, 50, 50, 50}, 4, "assets/ui/held_item.png") {
}

void HeldItemDisplay::onNotify(const Vector2& data, const Event event) {
    switch (event) {
        case PLAYER_ITEM_UNEQUIPPED:
            getRenderer()->setSprite(0);
            break;
        case CIRCLE_ITEM_PICKED_UP:
            getRenderer()->setSprite(1);
            break;
        case SQUARED_ITEM_PICKED_UP:
            getRenderer()->setSprite(2);
            break;
        case MISSILE_ITEM_PICKED_UP:
            getRenderer()->setSprite(3);
            break;
        default:
            break;
    }
}