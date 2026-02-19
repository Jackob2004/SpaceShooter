#include "HealthBarDisplay.h"

#include <cmath>

#include "components/SpriteRenderer.h"

HealthBarDisplay::HealthBarDisplay() :
    Display({10, 10, 100, 50}, TOTAL_SPRITES, "assets/ui/health_bar.png") {
    getRenderer()->setSprite(6);
}

void HealthBarDisplay::onNotify(const Vector2& data, const Event event) {
    if (event != PLAYER_DAMAGED && event != PLAYER_HEALTH_CHANGED) return;

    const float health = data.x;
    const float maxHealth = data.y;

    int spriteIndex = std::floor((health / maxHealth) * (TOTAL_SPRITES - 1));
    spriteIndex = (health > 0 && spriteIndex == 0) ? 1 : spriteIndex;
    getRenderer()->setSprite(std::clamp(spriteIndex, 0, TOTAL_SPRITES - 1));
}