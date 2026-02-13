#include "KamikazeDyingState.h"

#include <iostream>

#include "core/Game.h"
#include "entities/enemies/KamikazeEnemy.h"
#include "utils/MathUtils.h"

void KamikazeDyingState::enter(KamikazeEnemy& kamikazeEnemy) {
    Vector2 velocity = MathUtils::subtrackVectors(kamikazeEnemy.getTarget()->getPosition(), kamikazeEnemy.getPosition());
    velocity = MathUtils::normalizeVector(velocity);
    velocity = MathUtils::scaleVector(velocity, 350.0f);

    kamikazeEnemy.setVelocity(velocity);
}

KamikazeEnemyState* KamikazeDyingState::update(KamikazeEnemy& kamikazeEnemy) {
    if (Game::isOutOfVerticalBounds(kamikazeEnemy.getPosition())) {
        kamikazeEnemy.setHealth(0);
    }

    return nullptr;
}