#include "CandyShootingState.h"

#include "entities/enemies/CandyEnemy.h"
#include "CandyPausingState.h"
#include "utils/MathUtils.h"

Vector2 computeProjectilePosition(const CandyEnemy& enemy) {
    const int randomOffsetX = MathUtils::getRandomInRange(-100, 100);
    const int randomOffsetY = MathUtils::getRandomInRange(-50, 20);

    const Vector2 position = {
        .x = enemy.getPosition().x + static_cast<float>(randomOffsetX),
        .y = enemy.getPosition().y + enemy.getEntityHeight() + static_cast<float>(randomOffsetY),
    };

    return position;
}

void CandyShootingState::enter(CandyEnemy& candyEnemy) {
    candyEnemy.stateTimeLeft = 5;
    candyEnemy.setVelocity({0, 0});
}

CandyEnemyState* CandyShootingState::update(CandyEnemy& candyEnemy) {
    if (candyEnemy.stateTimeLeft < 0) {
        return &CandyEnemyState::pausing;
    }

    candyEnemy.notify(computeProjectilePosition(candyEnemy), ENEMY_PROJECTILE_SHOOT);
    return nullptr;
}