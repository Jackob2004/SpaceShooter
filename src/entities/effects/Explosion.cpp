#include "Explosion.h"

#include "core/Game.h"
#include "core/TextureManager.h"

Explosion::Explosion() :
    Entity({0, 0, 100, 100},
           new SpriteRenderer(FRAMES, TextureManager::getTexture("assets/effects/explosion.png")),
           {0, 0}),
    timeLeft(0) {
}

void Explosion::init(const Vector2 spawnPoint) {
    setPosition(spawnPoint);
    timeLeft = FPS / FRAMES_SPEED * FRAMES;
    damaged.clear();
}

void Explosion::update() {
    if (!isAlive()) return;
    getRenderer()->advanceSprite();

    timeLeft--;
}

void Explosion::render() {
    if (!isAlive()) return;
    Entity::render();
}

bool Explosion::isAlive() const {
    return timeLeft > 0;
}

void Explosion::takeDamage(int damage) {
}

int Explosion::getDamage() {
    return 0;
}

int Explosion::getDamage(Damageable* target) {
    if (damaged.contains(target)) {
        return 0;
    }
    damaged.insert(target);

    return 50;
}