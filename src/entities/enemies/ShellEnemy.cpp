#include "ShellEnemy.h"

#include "core/TextureManager.h"
#include "states/ShellAdvancingState.h"

ShellEnemy::ShellEnemy() :
    Entity({0, 0, 50, 50},
           new SpriteRenderer(5, TextureManager::getTexture("assets/enemies/shell_enemy.png")),
           {0, 0}),
    health(0),
    state(new ShellAdvancingState(*this)) {
}

void ShellEnemy::update() {
    if (!isAlive()) return;
    Entity::update();
    getRenderer()->advanceSprite();

    if (ShellEnemyState* updatedState = state->update(*this); updatedState != nullptr) {
        delete state;
        state = updatedState;
    }
}

void ShellEnemy::render() {
    if (!isAlive()) return;
    Entity::render();
}

void ShellEnemy::init(const Vector2 spawnPoint) {
    setPosition(spawnPoint);
    health = 100;
}

bool ShellEnemy::isAlive() const {
    return health > 0;
}

void ShellEnemy::takeDamage(const int damage) {
    health -= damage;

    if (!isAlive()) {
        notify(getPosition(), ENEMY_KILLED);
    }
}

int ShellEnemy::getDamage(Damageable* target) {
    return 0;
}

Player* ShellEnemy::getTarget() const {
    return target;
}

void ShellEnemy::setTarget(Player* player) {
    target = player;
}

void ShellEnemy::setHealth(const int updatedHealth) {
    health = updatedHealth;
}