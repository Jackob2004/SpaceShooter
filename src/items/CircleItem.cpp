#include "CircleItem.h"

#include "entities/Player.h"

CircleItem::CircleItem() :
    Item(4) {
}

bool CircleItem::processInput(Player& player) {
    bool succeeded = true;
    if (IsKeyPressed(KEY_Q)) {
        constexpr float gap = 60;
        Vector2 spawnPoint = {
            .x = player.getPosition().x - gap,
            .y = player.getPosition().y - player.getEntityHeight()
        };

        for (int i = 0; i < 3; i++) {
            player.notify(spawnPoint, PLAYER_CIRCLE_PROJECTILE_SHOOT);
            spawnPoint.x += gap;
        }
        succeeded = Item::processInput(player);
    }

    return succeeded;
}


