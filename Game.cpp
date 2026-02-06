#include "Game.h"

#include <iostream>

Game::Game() :
    backgroundRenderer(std::make_unique<SpriteRenderer>(2, "assets/background.png")),
    backgroundDestRect({0, 0, SCREEN_WIDTH, SCREEN_HEIGHT}),
    player(50, 50, {static_cast<float>(SCREEN_WIDTH) / 2 - 25, SCREEN_HEIGHT - 100}) {
    player.addObserver(this);
}

void Game::processInput() {
    player.processInput();
}

void Game::update() {
    backgroundRenderer->advanceSprite();
    player.update();

    if (player.getPosition().x + player.getEntityHeight() > SCREEN_WIDTH) {
        player.setPosition({SCREEN_WIDTH - player.getEntityWidth(), SCREEN_HEIGHT - 100});
    } else if (player.getPosition().x < 0) {
        player.setPosition({0, SCREEN_HEIGHT - 100});
    }
}

void Game::render() {
    DrawTexturePro(backgroundRenderer->getTexture(),
                   backgroundRenderer->getSource(),
                   backgroundDestRect,
                   {0, 0},
                   0.0f,
                   WHITE);
    player.render();
}

void Game::onNotify(Entity& data, Event event) {
    switch (event) {
        case PLAYER_BEAM_SHOOT:
            std::cout << "Spawning projectile" << std::endl;
            break;
    }
}