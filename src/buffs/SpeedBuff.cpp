#include "SpeedBuff.h"

#include "entities/Player.h"

SpeedBuff::SpeedBuff() :
    ActiveBuff(MAX_ALIVE),
    speed(100) {
}

bool SpeedBuff::update(Player& player) {
    if (getTimeAlive() > MAX_ALIVE * 0.7) {
        speed--;
    }

    player.setSpeed(static_cast<float>(speed) + player.getSpeed());

    return ActiveBuff::update(player);
}

void SpeedBuff::onDeactivate(Player& player) {
    player.setSpeed(0);
}