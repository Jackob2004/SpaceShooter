#include "BeamProjectile.h"

#include "Game.h"

Texture2D BeamProjectile::texture = {0};

BeamProjectile::BeamProjectile() :
    Entity({0, 0, 50, 50},
           new SpriteRenderer(2, texture),
           {0, -200}),
    alive(false) {
}

void BeamProjectile::init(const Vector2 spawnPoint) {
    setPosition(spawnPoint);
    alive = true;
}

void BeamProjectile::initTexture() {
    if (texture.id == 0) {
        texture = LoadTexture("assets/player/projectiles/beam.png");
    }
}

void BeamProjectile::unloadTexture() {
    if (texture.id != 0) {
        UnloadTexture(texture);
        texture = {0};
    }
}

void BeamProjectile::update() {
    if (!isAlive()) return;
    Entity::update();
    getRenderer()->advanceSprite();

    const Vector2 position = {
        .x = getPosition().x,
        .y = getPosition().y + getEntityHeight()
    };

    if (Game::isOutOfBounds(position)) {
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