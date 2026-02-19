#include "RandomPowerup.h"

#include "core/Game.h"
#include "utils/MathUtils.h"


RandomPowerup::RandomPowerup() :
    RandomPowerup(MathUtils::getRandomInRange(0, 2)) {
}

RandomPowerup::RandomPowerup(const int randomIndex) :
    Entity({0, 0, 40, 40},
           new SpriteRenderer(3, "assets/powerups/powerup.png"),
           {0, 70}),
    powerupIndex(randomIndex),
    alive(false) {
    getRenderer()->setSprite(powerupIndex);
}

void RandomPowerup::update() {
    if (!isAlive()) return;
    Entity::update();

    if (Game::isOutOfVerticalBounds(getPosition())) {
        alive = false;
        notify(getPosition(), POWERUP_DIED);
    }
}

void RandomPowerup::render() {
    if (!isAlive()) return;
    Entity::render();
}

void RandomPowerup::init(const Vector2 spawnPoint) {
    setPosition(spawnPoint);
    alive = true;
}

bool RandomPowerup::isAlive() const {
    return alive;
}

int RandomPowerup::getDamage(Damageable* target) {
    return 0;
}

void RandomPowerup::takeDamage(int damage) {
    if (!isAlive()) return;
    alive = false;
    notify(getPosition(), POWERUPS[powerupIndex]);
    notify(getPosition(), POWERUP_DIED);
}