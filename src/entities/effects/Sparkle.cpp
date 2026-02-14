#include "Sparkle.h"

#include "core/Game.h"
#include "core/TextureManager.h"

Sparkle::Sparkle():
    Entity({0, 0, 80, 80},
           new SpriteRenderer(FRAMES, TextureManager::getTexture("assets/effects/sparkle.png")),
           {0, 0}),
    timeLeft(0),
    updatesCounter(0) {
}

void Sparkle::init(const Vector2 spawnPoint) {
    setPosition(spawnPoint);
    constexpr int LIFE_CYCLES = 4;
    timeLeft = (FPS / FRAMES_SPEED * FRAMES) * LIFE_CYCLES;
}

void Sparkle::update() {
    if (!isAlive()) return;
    Entity::update();
    getRenderer()->advanceSprite();

    timeLeft--;
    updatesCounter++;
}

void Sparkle::render() {
    if (!isAlive()) return;
    Entity::render();
}

bool Sparkle::isAlive() const {
    return timeLeft > 0;
}

void Sparkle::takeDamage(int damage) {
}

int Sparkle::getDamage() {
    if (updatesCounter > DAMAGE_COOLDOWN) {
        updatesCounter = 0;
        return 10;
    }

    return 0;
}