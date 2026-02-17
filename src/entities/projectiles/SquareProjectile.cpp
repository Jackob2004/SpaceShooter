#include "SquareProjectile.h"

#include "core/Game.h"
#include "core/TextureManager.h"

SquareProjectile::SquareProjectile() :
    Entity({0, 0, 40, 40},
           new SpriteRenderer(8, TextureManager::getTexture("assets/player/projectiles/square_projectile.png")),
           {0, -180}),
    alive(false) {
}

void SquareProjectile::init(const Vector2 spawnPoint) {
    setPosition(spawnPoint);
    alive = true;
    damaged.clear();
}

void SquareProjectile::update() {
    if (!isAlive()) return;
    Entity::update();
    getRenderer()->advanceSprite();

    const Vector2 position = {
        .x = getPosition().x,
        .y = getPosition().y + getEntityHeight()
    };

    if (Game::isOutOfVerticalBounds(position)) {
        alive = false;
    }
}

void SquareProjectile::render() {
    if (!isAlive()) return;
    Entity::render();
}

bool SquareProjectile::isAlive() const {
    return alive;
}

void SquareProjectile::takeDamage(int damage) {
}

int SquareProjectile::getDamage(Damageable* target) {
    if (damaged.contains(target)) {
        return 0;
    }
    damaged.insert(target);

    return 30;
}