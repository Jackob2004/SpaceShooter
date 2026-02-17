#include "CandyAdvancingState.h"
#include "core/Game.h"
#include "entities/enemies/CandyEnemy.h"
#include "entities/enemies/states/CandyShootingState.h"

void CandyAdvancingState::enter(CandyEnemy& candyEnemy) {
    candyEnemy.setStateTimeLeft(150);
    candyEnemy.setVelocity({0, 50});
}

CandyEnemyState* CandyAdvancingState::update(CandyEnemy& candyEnemy) {
    if (Game::isOutOfVerticalBounds(candyEnemy.getPosition())) {
        candyEnemy.notify(candyEnemy.getPosition(), ENEMY_DIED);
        candyEnemy.setHealth(0);
    }

    if (candyEnemy.getStateTimeLeft() <= 0) {
        return &CandyEnemyState::shooting;
    }

    return nullptr;
}