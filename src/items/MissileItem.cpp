#include "MissileItem.h"
#include "entities/Player.h"

MissileItem::MissileItem() :
    Item(5) {
}

bool MissileItem::processInput(Player& player) {
    bool succeeded = true;
    if (IsKeyPressed(KEY_Q)) {
        const Vector2 missileSpawnPoint = {
            .x = player.getPosition().x,
            .y = player.getPosition().y - player.getEntityHeight()
        };

        player.notify(missileSpawnPoint, PLAYER_MISSILE_LAUNCHED);
        succeeded = Item::processInput(player);
    }

    return succeeded;
}