#include "Game.h"

Game::Game() :
    backgroundRenderer(std::make_unique<SpriteRenderer>(2, "assets/background.png")),
    backgroundDestRect({0, 0, SCREEN_WIDTH, SCREEN_HEIGHT}),
    player(50, 50, {static_cast<float>(SCREEN_WIDTH) / 2 - 25, SCREEN_HEIGHT - 100}), beamPool(20){
    player.addObserver(this);
}

void Game::processInput() {
    player.processInput();
}

void Game::update() {
    backgroundRenderer->advanceSprite();
    player.update();
    enemy.update();
    beamPool.update();

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
    enemy.render();
    beamPool.render();
}

bool Game::isOutOfBounds(const Vector2 position) {
    return position.y < 0 || position.y > SCREEN_HEIGHT;
}

void Game::onNotify(Entity& data, Event event) {
    switch (event) {
        case PLAYER_BEAM_SHOOT:
            spawnPlayerProjectile(data);
            break;
    }
}

void Game::spawnPlayerProjectile(const Entity& shooter) {
    const Vector2 position = {
        .x = shooter.getPosition().x,
        .y = shooter.getPosition().y - shooter.getEntityHeight()
    };

    beamPool.create(position);
}