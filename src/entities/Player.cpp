#include "Player.h"

Player::Player(const float playerWidth, const float playerHeight, const Vector2 spawPoint) :
    Entity({spawPoint.x, spawPoint.y, playerWidth, playerHeight},
           new SpriteRenderer(3, "assets/player/player_ship.png"),
           {0, 0}),
    playerSprite(IDLE),
    boostersDestinationRect({getPosition().x, getPosition().y, 50, 50}),
    health(500),
    item(nullptr) {
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
        setVelocity({-80, 0});
        playerSprite = FLY_LEFT;
    } else if (IsKeyDown(KEY_D) || IsKeyDown(KEY_KP_6)) {
        setVelocity({80, 0});
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

void Player::takeDamage(const int damage) {
    health -= damage;
}

int Player::getDamage(Damageable* target) {
    return 100;
}

void Player::equipItem(Item* newItem) {
    delete item;
    item = newItem;
}