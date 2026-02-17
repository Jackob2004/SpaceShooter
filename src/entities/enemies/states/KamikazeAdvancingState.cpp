#include "KamikazeAdvancingState.h"

#include "core/Game.h"
#include "entities/enemies/KamikazeEnemy.h"
#include "utils/MathUtils.h"
#include "KamikazeTargetingState.h"

void KamikazeAdvancingState::enter(KamikazeEnemy& kamikazeEnemy) {
    constexpr float velocity = 150;
    const int xDirModifier = (MathUtils::getRandomInRange(0, 1)) ? 1 : -1;

    kamikazeEnemy.setVelocity({velocity * static_cast<float>(xDirModifier), velocity});
    kamikazeEnemy.setStateTime(50);
}

KamikazeEnemyState* KamikazeAdvancingState::update(KamikazeEnemy& kamikazeEnemy) {
    if (kamikazeEnemy.getStateTime() < 0) {
        return &KamikazeEnemyState::targeting;
    }

    if (Game::isOutOfHorizontalBounds(kamikazeEnemy.getPosition())) {
        const Vector2 velocity = {
            .x = kamikazeEnemy.getVelocity().x * -1,
            .y = kamikazeEnemy.getVelocity().y
        };

        kamikazeEnemy.setVelocity(velocity);
    }

    if (Game::isOutOfVerticalBounds(kamikazeEnemy.getPosition())) {
        kamikazeEnemy.setHealth(0);
        kamikazeEnemy.notify(kamikazeEnemy.getPosition(), ENEMY_DIED);
    }

    return nullptr;
}
