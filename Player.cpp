#include "Player.h"

Player::Player(const float playerWidth, const float playerHeight, const Vector2 spawPoint) :
    Entity({spawPoint.x, spawPoint.y, playerWidth, playerHeight},
           std::make_unique<SpriteRenderer>(3, "assets/player/player_ship.png"),
           {0, 0},
           100),
    playerSprite(IDLE),
    boostersDestinationRect({destinationRect.x, destinationRect.y, 50, 50}) {
    spriteRenderer->setSprite(IDLE);
    boosterRenderers.push_back(std::make_unique<SpriteRenderer>(2, "assets/player/boosters_left.png"));
    boosterRenderers.push_back(std::make_unique<SpriteRenderer>(2, "assets/player/boosters.png"));
    boosterRenderers.push_back(std::make_unique<SpriteRenderer>(2, "assets/player/boosters_right.png"));
}

void Player::processInput() {
    const PlayerSprite oldSprite = playerSprite;

    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_KP_4)) {
        velocity.x = -80;
        playerSprite = FLY_LEFT;
    } else if (IsKeyDown(KEY_D) || IsKeyDown(KEY_KP_6)) {
        velocity.x = 80;
        playerSprite = FLY_RIGHT;
    } else {
        playerSprite = IDLE;
        velocity.x = 0;
    }

    if (playerSprite != oldSprite) {
        spriteRenderer->setSprite(playerSprite);
    }
}

void Player::update() {
    Entity::update();
    boosterRenderers[playerSprite]->advanceSprite();
    boostersDestinationRect.x = destinationRect.x;
    boostersDestinationRect.y = destinationRect.y + destinationRect.height;
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

void Player::setPosition(const Vector2 newPosition) {
    destinationRect.x = newPosition.x;
    destinationRect.y = newPosition.y;
}

Vector2 Player::getPosition() const {
    return {destinationRect.x, destinationRect.y};
}

float Player::getPlayerWidth() const {
    return destinationRect.width;
}

float Player::getPlayerHeight() const {
    return destinationRect.height;
}