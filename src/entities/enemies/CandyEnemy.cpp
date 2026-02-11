#include "CandyEnemy.h"

#include "core/TextureManager.h"
#include "entities/enemies/states/CandyEnemyState.h"
#include "entities/enemies/states/CandyAdvancingState.h"

CandyEnemy::CandyEnemy() :
    Entity({0, 0, 50, 50},
           new SpriteRenderer(4, TextureManager::getTexture("assets/enemies/candy_enemy.png")),
           {0, 0}),
    health(0) {
    state = &CandyEnemyState::advancing;
    state->enter(*this);
}

void CandyEnemy::update() {
    if (!isAlive()) return;
    Entity::update();
    getRenderer()->advanceSprite();
    stateTimeLeft--;

    if (CandyEnemyState* updatedState = state->update(*this); updatedState != nullptr) {
        state = updatedState;
        state->enter(*this);
    }
}

void CandyEnemy::render() {
    if (!isAlive()) return;
    Entity::render();
}

void CandyEnemy::init(const Vector2 spawnPoint) {
    setPosition(spawnPoint);
    health = 100;
}

void CandyEnemy::setTarget(Player* player) {
    target = player;
}

bool CandyEnemy::isAlive() const {
    return health > 0;
}

void CandyEnemy::setStateTimeLeft(const int time) {
    stateTimeLeft = time;
}

int CandyEnemy::getStateTimeLeft() const {
    return stateTimeLeft;
}

void CandyEnemy::setState(CandyEnemyState* updatedState) {
    state = updatedState;
}

void CandyEnemy::setHealth(const int updatedHealth) {
    health = updatedHealth;
}