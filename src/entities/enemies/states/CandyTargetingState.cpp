#include "CandyTargetingState.h"

#include "entities/enemies/CandyEnemy.h"
#include "CandyAdvancingState.h"
#include "core/Game.h"

bool isInRange(const Vector2 targetPosition, const CandyEnemy& candyEnemy) {
    return std::abs(targetPosition.x - candyEnemy.getPosition().x)  <= (SCREEN_WIDTH * 0.10);
}

Vector2 computeMissilePosition(const CandyEnemy& candyEnemy) {
    const Vector2 position = {
        .x = candyEnemy.getPosition().x,
        .y = candyEnemy.getPosition().y + candyEnemy.getEntityHeight()
    };

    return position;
}

void CandyTargetingState::enter(CandyEnemy& candyEnemy) {
    candyEnemy.stateTimeLeft = 400;

    const float dirModifier = (candyEnemy.getPosition().x > static_cast<float>(SCREEN_WIDTH) / 2) ? 1 : -1;
    candyEnemy.setVelocity({100 * dirModifier, 0});
}

CandyEnemyState* CandyTargetingState::update(CandyEnemy& candyEnemy) {
    if (candyEnemy.stateTimeLeft < 0) {
        return &CandyEnemyState::advancing;
    }

    if (candyEnemy.target != nullptr && isInRange(candyEnemy.target->getPosition(), candyEnemy)) {
        candyEnemy.notify(computeMissilePosition(candyEnemy), ENEMY_MISSILE_LAUNCHED);
        return &CandyEnemyState::advancing;
    }

    if (Game::isOutOfHorizontalBounds(candyEnemy.getPosition())) {
        candyEnemy.setVelocity({candyEnemy.getVelocity().x * -1, 0});
    }

    return nullptr;
}