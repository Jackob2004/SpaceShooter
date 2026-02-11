#include "EnemyProjectile.h"

#include "core/Game.h"
#include "core/TextureManager.h"

EnemyProjectile::EnemyProjectile() :
    Entity({0, 0, 50, 50},
           new SpriteRenderer(2,
                              TextureManager::getTexture("assets/enemies/projectiles/enemy_projectile.png")),
           {0, 200}),
    alive(false) {
}

void EnemyProjectile::init(const Vector2 spawnPoint) {
    setPosition(spawnPoint);
    alive = true;
}

void EnemyProjectile::update() {
    if (!isAlive()) return;
    Entity::update();
    getRenderer()->advanceSprite();

    const Vector2 position = {
        .x = getPosition().x,
        .y = getPosition().y
    };

    if (Game::isOutOfVerticalBounds(position)) {
        alive = false;
    }
}

void EnemyProjectile::render() {
    if (!alive) return;
    Entity::render();
}

bool EnemyProjectile::isAlive() const {
    return alive;
}