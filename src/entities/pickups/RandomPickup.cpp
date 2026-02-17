#include "RandomPickup.h"

#include "core/Game.h"
#include "core/TextureManager.h"
#include "utils/MathUtils.h"

RandomPickup::RandomPickup() :
    RandomPickup(MathUtils::getRandomInRange(0, 2)) {
}

RandomPickup::RandomPickup(const int randomOption) :
    Entity({0, 0, 40, 40},
           new SpriteRenderer(3, TextureManager::getTexture("assets/items/pickups.png")),
           {0, 50}),
    randomOption(randomOption),
    pickedUp(true) {
    getRenderer()->setSprite(randomOption);
}

void RandomPickup::init(const Vector2 spawnPoint) {
    setPosition(spawnPoint);
    pickedUp = false;
}

void RandomPickup::update() {
    if (!isAlive()) return;
    Entity::update();

    if (Game::isOutOfVerticalBounds(getPosition())) {
        pickedUp = true;
        notify(getPosition(), PICKUP_DIED);
    }
}

void RandomPickup::render() {
    if (!isAlive()) return;
    Entity::render();
}

bool RandomPickup::isAlive() const {
    return !pickedUp;
}

void RandomPickup::takeDamage(int damage) {
    if (!isAlive()) return;
    pickedUp = true;
    notify(getPosition(), options[randomOption].event);
    notify(getPosition(), PICKUP_DIED);
}

int RandomPickup::getDamage(Damageable* target) {
    return 0;
}