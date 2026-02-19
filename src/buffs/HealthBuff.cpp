#include "HealthBuff.h"

#include "entities/Player.h"

HealthBuff::HealthBuff() :
    ActiveBuff(5) {
}

bool HealthBuff::update(Player& player) {
    player.setHealth(player.getHealth() + REGENERATION_RATE);
    player.notify({static_cast<float>(player.getHealth()), static_cast<float>(Player::PLAYER_HEALTH)},
                  PLAYER_HEALTH_CHANGED);
    return ActiveBuff::update(player);
}

void HealthBuff::onDeactivate(Player& player) {
}