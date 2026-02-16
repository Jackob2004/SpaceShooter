#include "BeamProjectile.h"

#include "core/Game.h"
#include "core/TextureManager.h"

BeamProjectile::BeamProjectile() :
    Entity({0, 0, 50, 50},
           new SpriteRenderer(2, TextureManager::getTexture("assets/player/projectiles/beam.png")),
           {0, -200}),
    alive(false) {
}

void BeamProjectile::init(const Vector2 spawnPoint) {
    setPosition(spawnPoint);
    alive = true;
}

void BeamProjectile::update() {
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

void BeamProjectile::render() {
    if (!isAlive()) return;
    Entity::render();
}

bool BeamProjectile::isAlive() const {
    return alive;
}

void BeamProjectile::takeDamage(int damage) {
    alive = false;
}

int BeamProjectile::getDamage(Damageable* target) {
    return 40;
}