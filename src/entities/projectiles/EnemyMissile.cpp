#include "EnemyMissile.h"

#include "core/Game.h"
#include "core/TextureManager.h"
#include "cmath"

EnemyMissile::EnemyMissile() :
    Entity({0, 0, 50, 50},
           new SpriteRenderer(2,
                              TextureManager::getTexture("assets/enemies/projectiles/enemy_missile.png")),
           {0, VELOCITY_Y}),
    alive(false) {
}

void EnemyMissile::init(const Vector2 spawnPoint) {
    setPosition(spawnPoint);
    alive = true;
}

void EnemyMissile::update() {
    if (!alive) return;

    const float velocityX = AMPLITUDE * FREQUENCY * std::cos(FREQUENCY * lifeTime);
    setVelocity({velocityX, VELOCITY_Y});
    lifeTime += GetFrameTime();

    Entity::update();
    getRenderer()->advanceSprite();

    const Vector2 criticalPoint = {
        .x = getPosition().x,
        .y = getPosition().y + getEntityHeight() * 2
    };

    if (Game::isOutOfVerticalBounds(criticalPoint)) {
        notify(getPosition(), ENEMY_MISSILE_EXPLODED);
        alive = false;
    }
}

void EnemyMissile::render() {
    if (!alive) return;
    Entity::render();
}

bool EnemyMissile::isAlive() const {
    return alive;
}