#include "Player.h"

#include <iostream>

#include "buffs/HealthBuff.h"

Player::Player(const float playerWidth, const float playerHeight, const Vector2 spawPoint) :
    Entity({spawPoint.x, spawPoint.y, playerWidth, playerHeight},
           new SpriteRenderer(3, "assets/player/player_ship.png"),
           {0, 0}),
    playerSprite(IDLE),
    boostersDestinationRect({getPosition().x, getPosition().y, 50, 50}),
    health(PLAYER_HEALTH),
    takenDamageModifier(1),
    item(nullptr),
    activeBuff(nullptr) {
    getRenderer()->setSprite(IDLE);
    boosterRenderers.push_back(std::make_unique<SpriteRenderer>(2, "assets/player/boosters_left.png"));
    boosterRenderers.push_back(std::make_unique<SpriteRenderer>(2, "assets/player/boosters.png"));
    boosterRenderers.push_back(std::make_unique<SpriteRenderer>(2, "assets/player/boosters_right.png"));
}

void Player::processInput() {
    const PlayerSprite oldSprite = playerSprite;

    if (item != nullptr && !item->processInput(*this)) {
        unequipItem();
    }

    if (IsKeyPressed(KEY_SPACE)) {
        notify(computeProjectilePosition(), PLAYER_BEAM_SHOOT);
    }

    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_KP_4)) {
        setVelocity({-PLAYER_SPEED, 0});
        playerSprite = FLY_LEFT;
    } else if (IsKeyDown(KEY_D) || IsKeyDown(KEY_KP_6)) {
        setVelocity({PLAYER_SPEED, 0});
        playerSprite = FLY_RIGHT;
    } else {
        playerSprite = IDLE;
        setVelocity({0, 0});
    }

    if (playerSprite != oldSprite) {
        getRenderer()->setSprite(playerSprite);
    }
}

void Player::update() {
    Entity::update();
    boosterRenderers[playerSprite]->advanceSprite();
    boostersDestinationRect.x = getPosition().x;
    boostersDestinationRect.y = getPosition().y + getEntityHeight();

    if (activeBuff != nullptr && !activeBuff->update(*this)) {
        deactivateBuff();
    }
}

void Player::render() {
    Entity::render();
    DrawTexturePro(boosterRenderers[playerSprite]->getTexture(),
                   boosterRenderers[playerSprite]->getSource(),
                   boostersDestinationRect,
                   {0, 0},
                   0.0f,
                   WHITE);
}

void Player::init(Vector2 spawnPoint) {
}

bool Player::isAlive() const {
    return health > 0;
}

Vector2 Player::computeProjectilePosition() const {
    const Vector2 position = {
        .x = getPosition().x,
        .y = getPosition().y - getEntityHeight()
    };

    return position;
}

void Player::unequipItem() {
    delete item;
    item = nullptr;
    notify(getPosition(), PLAYER_ITEM_UNEQUIPPED);
}

void Player::deactivateBuff() {
    activeBuff->onDeactivate(*this);
    delete activeBuff;
    activeBuff = nullptr;
}

void Player::takeDamage(const int damage) {
    const int actualDamage = takenDamageModifier * damage;
    health -= actualDamage;
    std::cout << actualDamage << std::endl;

    if (actualDamage > 0) {
        notify({static_cast<float>(health), PLAYER_HEALTH}, PLAYER_DAMAGED);
    }

    if (!isAlive()) {
        notify(getPosition(), PLAYER_DIED);
    }
}

int Player::getDamage(Damageable* target) {
    return 100;
}

void Player::equipItem(Item* newItem) {
    delete item;
    item = newItem;
}

void Player::activateBuff(ActiveBuff* buff) {
    if (activeBuff != nullptr) {
        activeBuff->onDeactivate(*this);
        delete activeBuff;
    }
    activeBuff = buff;
}

int Player::getHealth() const {
    return health;
}

void Player::setHealth(const int updatedHealth) {
    health = std::clamp(updatedHealth, 0, PLAYER_HEALTH);
}

void Player::setTakenDamageModifier(const float modifier) {
    takenDamageModifier = (modifier > 0) ? modifier : 1;
}