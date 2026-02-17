#include "KamikazeEnemy.h"

#include "core/TextureManager.h"
#include "states/KamikazeAdvancingState.h"

KamikazeEnemy::KamikazeEnemy():
    Entity({0, 0, 50, 50},
           new SpriteRenderer(6, TextureManager::getTexture("assets/enemies/kamikaze_enemy.png")),
           {0, 0}),
    health(0),
    state(&KamikazeEnemyState::advancing) {
    state->enter(*this);
}

void KamikazeEnemy::update() {
    if (!isAlive()) return;
    Entity::update();
    getRenderer()->advanceSprite();
    stateTimeLeft--;

    if (KamikazeEnemyState* updatedState = state->update(*this); updatedState != nullptr) {
        state = updatedState;
        state->enter(*this);
    }
}

void KamikazeEnemy::render() {
    if (!isAlive()) return;
    Entity::render();
}

void KamikazeEnemy::init(const Vector2 spawnPoint) {
    setPosition(spawnPoint);
    health = 100;
}

bool KamikazeEnemy::isAlive() const {
    return health > 0;
}

void KamikazeEnemy::takeDamage(const int damage) {
    health -= damage;

    if (!isAlive()) {
        notify(getPosition(), ENEMY_KILLED);
    }
}

int KamikazeEnemy::getDamage(Damageable* target) {
    return 40;
}

void KamikazeEnemy::setStateTime(const int time) {
    stateTimeLeft = time;
}

int KamikazeEnemy::getStateTime() const {
    return stateTimeLeft;
}

Player* KamikazeEnemy::getTarget() const {
    return target;
}

void KamikazeEnemy::setTarget(Player* target) {
    this->target = target;
}

void KamikazeEnemy::setHealth(const int health) {
    this->health = health;
}