#include "ShellAdvancingState.h"

#include "ShellTrailingState.h"
#include "core/Game.h"
#include "entities/enemies/ShellEnemy.h"
#include "utils/MathUtils.h"

ShellAdvancingState::ShellAdvancingState(ShellEnemy& shellEnemy) :
    currentVelocity(MAX_VELOCITY) {
    shellEnemy.setVelocity({0, static_cast<float>(currentVelocity)});
}

ShellEnemyState* ShellAdvancingState::update(ShellEnemy& shellEnemy) {
    currentVelocity = (currentVelocity <= 0) ? MAX_VELOCITY : currentVelocity - 1;
    shellEnemy.setVelocity({0, static_cast<float>(currentVelocity)});

    if (MathUtils::isInHorizontalRange(shellEnemy.getPosition(), shellEnemy.getTarget()->getPosition(), 0.40) &&
        MathUtils::isInVerticalRange(shellEnemy.getPosition(), shellEnemy.getTarget()->getPosition(), 0.40)) {
        return new ShellTrailingState(shellEnemy);
    }

    if (Game::isOutOfVerticalBounds(shellEnemy.getPosition())) {
        shellEnemy.setHealth(0);
    }

    return nullptr;
}