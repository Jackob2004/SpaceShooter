#include "CircleProjectile.h"

#include "core/Game.h"
#include "core/TextureManager.h"

CircleProjectile::CircleProjectile() :
    Entity({0, 0, 50, 50},
           new SpriteRenderer(4, TextureManager::getTexture("assets/player/projectiles/circle_projectile.png")),
           {0, 0}),
    yVelocity(0),
    alive(false) {
}

void CircleProjectile::init(const Vector2 spawnPoint) {
    setPosition(spawnPoint);
    alive = true;
    yVelocity = -1;
}

void CircleProjectile::update() {
    if (!isAlive()) return;
    Entity::update();
    getRenderer()->advanceSprite();

    setVelocity({0, yVelocity});
    yVelocity *= 1.06;

    const Vector2 position = {
        .x = getPosition().x,
        .y = getPosition().y + getEntityHeight()
    };

    if (Game::isOutOfVerticalBounds(position)) {
        alive = false;
    }
}

void CircleProjectile::render() {
    if (!isAlive()) return;
    Entity::render();
}

bool CircleProjectile::isAlive() const {
    return alive;
}

void CircleProjectile::takeDamage(int damage) {
    alive = false;
}

int CircleProjectile::getDamage(Damageable* target) {
    return 35;
}