#include "SquareItem.h"
#include "entities/Player.h"

SquareItem::SquareItem() :
    Item(10) {
}

bool SquareItem::processInput(Player& player) {
    bool succeeded = true;
    if (IsKeyPressed(KEY_Q) || IsKeyPressed(KEY_DOWN)) {
        const Vector2 squareSpawnPoint = {
            .x = player.getPosition().x,
            .y = player.getPosition().y - player.getEntityHeight() / 2
        };

        player.notify(squareSpawnPoint, PLAYER_SQUARED_PROJECTILE_SHOOT);
        succeeded = Item::processInput(player);
    }

    return succeeded;
}