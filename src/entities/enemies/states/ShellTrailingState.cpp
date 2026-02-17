#include "ShellTrailingState.h"

#include "core/Game.h"
#include "entities/enemies/ShellEnemy.h"

ShellTrailingState::ShellTrailingState() :
    lastTrailingYPosition(0) {
}

ShellEnemyState* ShellTrailingState::update(ShellEnemy& shellEnemy) {
    if (shellEnemy.getPosition().y - lastTrailingYPosition > TRAILING_GAP) {
        shellEnemy.notify(shellEnemy.getPosition(), ENEMY_SPARKLE_SPAWNED);
        lastTrailingYPosition = shellEnemy.getPosition().y;
    }

    if (Game::isOutOfVerticalBounds(shellEnemy.getPosition())) {
        shellEnemy.setHealth(0);
        shellEnemy.notify(shellEnemy.getPosition(), ENEMY_DIED);
    }

    return nullptr;
}

void ShellTrailingState::enter(ShellEnemy& shellEnemy) {
    shellEnemy.setVelocity({0, 100});
}
