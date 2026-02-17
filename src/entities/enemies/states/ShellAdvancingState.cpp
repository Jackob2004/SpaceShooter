#include "ShellAdvancingState.h"

#include "ShellTrailingState.h"
#include "core/Game.h"
#include "entities/enemies/ShellEnemy.h"
#include "utils/MathUtils.h"

ShellAdvancingState::ShellAdvancingState() :
    currentVelocity(MAX_VELOCITY) {
}

ShellEnemyState* ShellAdvancingState::update(ShellEnemy& shellEnemy) {
    currentVelocity = (currentVelocity <= 0) ? MAX_VELOCITY : currentVelocity - 1;
    shellEnemy.setVelocity({0, static_cast<float>(currentVelocity)});

    if (MathUtils::isInHorizontalRange(shellEnemy.getPosition(), shellEnemy.getTarget()->getPosition(), 0.40) &&
        MathUtils::isInVerticalRange(shellEnemy.getPosition(), shellEnemy.getTarget()->getPosition(), 0.40)) {
        return new ShellTrailingState();
    }

    if (Game::isOutOfVerticalBounds(shellEnemy.getPosition())) {
        shellEnemy.setHealth(0);
        shellEnemy.notify(shellEnemy.getPosition(), ENEMY_DIED);
    }

    return nullptr;
}

void ShellAdvancingState::enter(ShellEnemy& shellEnemy) {
    shellEnemy.setVelocity({0, static_cast<float>(currentVelocity)});
}