#include "CandyPausingState.h"

#include "entities/enemies/CandyEnemy.h"
#include "CandyTargetingState.h"

void CandyPausingState::enter(CandyEnemy& candyEnemy) {
    candyEnemy.setStateTimeLeft(100);
    candyEnemy.setVelocity({0, -10});
}

CandyEnemyState* CandyPausingState::update(CandyEnemy& candyEnemy) {
    if (candyEnemy.getStateTimeLeft() < 0) {
        return &CandyPausingState::targeting;
    }

    return nullptr;
}