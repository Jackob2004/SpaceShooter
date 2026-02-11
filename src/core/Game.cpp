#include "Game.h"

#include <iostream>

Game::Game() :
    backgroundRenderer(std::make_unique<SpriteRenderer>(2, "assets/background.png")),
    backgroundDestRect({0, 0, SCREEN_WIDTH, SCREEN_HEIGHT}),
    player(50, 50, {static_cast<float>(SCREEN_WIDTH) / 2 - 25, SCREEN_HEIGHT - 100}),
    beamPool(20),
    candyEnemyPool(20),
    enemyProjectilePool(100),
    enemyMissilePool(25),
    enemyExplosionPool(25) {
    player.addObserver(this);
    enemyMissilePool.forEachEntity([this](EnemyMissile& missile) {
        missile.addObserver(this);
    });
    candyEnemyPool.forEachEntity([this] (CandyEnemy& enemy) {
        enemy.addObserver(this);
        enemy.setTarget(&player);
    });
}

void Game::processInput() {
    player.processInput();
}

void Game::update() {
    backgroundRenderer->advanceSprite();
    player.update();
    beamPool.update();
    candyEnemyPool.update();
    enemyProjectilePool.update();
    enemyMissilePool.update();
    enemyExplosionPool.update();

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
    beamPool.render();
    candyEnemyPool.render();
    enemyProjectilePool.render();
    enemyMissilePool.render();
    enemyExplosionPool.render();
}

bool Game::isOutOfVerticalBounds(const Vector2 position) {
    return position.y < 0 || position.y > SCREEN_HEIGHT;
}

bool Game::isOutOfHorizontalBounds(const Vector2 position) {
    return position.x < 0 || position.x > SCREEN_WIDTH;
}

void Game::onNotify(const Vector2& data, Event event) {
    switch (event) {
        case PLAYER_BEAM_SHOOT:
            beamPool.create(data);
            break;
        case ENEMY_PROJECTILE_SHOOT:
            enemyProjectilePool.create(data);
            break;
        case ENEMY_MISSILE_LAUNCHED:
            enemyMissilePool.create(data);
            break;
        case ENEMY_MISSILE_EXPLODED:
            enemyExplosionPool.create(data);
        default:
            break;
    }
}