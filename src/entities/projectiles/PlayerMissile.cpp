#include "PlayerMissile.h"

#include "core/Game.h"
#include "core/TextureManager.h"
#include "utils/MathUtils.h"

PlayerMissile::PlayerMissile() :
    Entity({0, 0, 50, 50},
           new SpriteRenderer(2, TextureManager::getTexture("assets/player/projectiles/player_missile.png")),
           {0, VELOCITY_Y}),
    alive(false),
    lifeTime(0) {
}

void PlayerMissile::init(const Vector2 spawnPoint) {
    setPosition(spawnPoint);
    alive = true;
    lifeTime = 0;
}

void PlayerMissile::update() {
    if (!isAlive()) return;
    Entity::update();
    getRenderer()->advanceSprite();

    setVelocity({MathUtils::computeOscillationSpeed(AMPLITUDE, FREQUENCY, lifeTime), VELOCITY_Y});
    lifeTime += GetFrameTime();

    if (Game::isOutOfVerticalBounds(getPosition())) {
        alive = false;
    }
}

void PlayerMissile::render() {
    if (!isAlive()) return;
    Entity::render();
}

bool PlayerMissile::isAlive() const {
    return alive;
}

void PlayerMissile::takeDamage(int damage) {
    if (!isAlive()) return;
    alive = false;

    const Vector2 spawnPoint = {
        .x = getPosition().x,
        .y = getPosition().y - getEntityHeight()
    };
    notify(spawnPoint, PLAYER_MISSILE_EXPLODED);
}

int PlayerMissile::getDamage(Damageable* target) {
    return 0;
}