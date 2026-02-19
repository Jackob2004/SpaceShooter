#include "ShieldBuff.h"

#include "core/Game.h"
#include "utils/MathUtils.h"

ShieldBuff::ShieldBuff() :
    ActiveBuff(8),
    passedTime(1) {
}

bool ShieldBuff::update(Player& player) {
    passedTime += GetFrameTime();
    if (passedTime >= 1) {
        passedTime = 0;
        const float modifier = static_cast<float>(MathUtils::getRandomInRange(4, 8)) * 0.1f;
        player.setTakenDamageModifier(modifier);
    }

    return ActiveBuff::update(player);
}

void ShieldBuff::onDeactivate(Player& player) {
    player.setTakenDamageModifier(1);
}

