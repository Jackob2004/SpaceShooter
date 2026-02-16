#include "Game.h"

#include <iostream>

#include "items/MissileItem.h"
#include "entities/effects/Explosion.h"
#include "entities/effects/Sparkle.h"
#include "entities/enemies/KamikazeEnemy.h"
#include "entities/enemies/ShellEnemy.h"
#include "entities/pickups/RandomPickup.h"
#include "entities/projectiles/BeamProjectile.h"
#include "entities/projectiles/EnemyProjectile.h"
#include "entities/projectiles/EnemyMissile.h"
#include "entities/projectiles/PlayerMissile.h"

Game::Game() :
    backgroundRenderer(std::make_unique<SpriteRenderer>(2, "assets/background.png")),
    backgroundDestRect({0, 0, SCREEN_WIDTH, SCREEN_HEIGHT}),
    player(50, 50, {static_cast<float>(SCREEN_WIDTH) / 2 - 25, SCREEN_HEIGHT - 100}),
    collisionManager(CollisionManager(&player)) {
    player.addObserver(this);

    initPlayerProjectilePools();
    initEnemyPools();
    initEnemyProjectilePools();
}

void Game::processInput() {
    player.processInput();
}

void Game::update() {
    backgroundRenderer->advanceSprite();
    player.update();
    poolManager.update();

    if (player.getPosition().x + player.getEntityHeight() > SCREEN_WIDTH) {
        player.setPosition({SCREEN_WIDTH - player.getEntityWidth(), SCREEN_HEIGHT - 100});
    } else if (player.getPosition().x < 0) {
        player.setPosition({0, SCREEN_HEIGHT - 100});
    }

    collisionManager.checkCollisions();
}

void Game::render() {
    DrawTexturePro(backgroundRenderer->getTexture(),
                   backgroundRenderer->getSource(),
                   backgroundDestRect,
                   {0, 0},
                   0.0f,
                   WHITE);
    player.render();
    poolManager.render();
}

bool Game::isOutOfVerticalBounds(const Vector2 position) {
    return position.y < 0 || position.y > SCREEN_HEIGHT;
}

bool Game::isOutOfHorizontalBounds(const Vector2 position) {
    return position.x < 0 || position.x > SCREEN_WIDTH;
}

void Game::onNotify(const Vector2& data, Event event) {
    if (IEntityPool* pool = poolManager.getPool(event)) {
        pool->create(data);
    }

    switch (event) {
        case MISSILE_ITEM_PICKED_UP:
            player.equipItem(new MissileItem());
            break;
        case PLAYER_ITEM_UNEQUIPPED:
            std::cout << "Player item unequipped" << std::endl;
            break;
        default:
            break;
    }
}

void Game::initPlayerProjectilePools() {
    EntityPool<PlayerMissile>* missilePool = poolManager.registerPool<PlayerMissile>(10, PLAYER_MISSILE_LAUNCHED);
    missilePool->forEachEntity([this](PlayerMissile& missile) {
        missile.addObserver(this);
    });

    collisionManager.registerPlayerProjectilePool(
        missilePool,
        poolManager.registerPool<Explosion>(10, PLAYER_MISSILE_EXPLODED),
        poolManager.registerPool<BeamProjectile>(20, PLAYER_BEAM_SHOOT));
}

void Game::initEnemyPools() {
    EntityPool<CandyEnemy>* candyPool = poolManager.registerPool<CandyEnemy>(40, CANDY_ENEMY_SPAWNED);
    candyPool->forEachEntity([this](CandyEnemy& enemy) {
        enemy.addObserver(this);
        enemy.setTarget(&player);
    });

    EntityPool<KamikazeEnemy>* kamikazePool = poolManager.registerPool<KamikazeEnemy>(40, KAMIKAZE_ENEMY_SPAWNED);
    kamikazePool->forEachEntity([this](KamikazeEnemy& enemy) {
        enemy.setTarget(&player);
    });

    EntityPool<ShellEnemy>* shellPool = poolManager.registerPool<ShellEnemy>(40, SHELL_ENEMY_SPAWNED);
    shellPool->forEachEntity([this](ShellEnemy& enemy) {
        enemy.addObserver(this);
        enemy.setTarget(&player);
    });

    collisionManager.registerEnemyPool(
        candyPool,
        kamikazePool,
        shellPool);
}

void Game::initEnemyProjectilePools() {
    EntityPool<EnemyMissile>* enemyMissilePool = poolManager.registerPool<EnemyMissile>(40, ENEMY_MISSILE_LAUNCHED);
    enemyMissilePool->forEachEntity([this](EnemyMissile& missile) { missile.addObserver(this); });

    collisionManager.registerEnemyProjectilePool(
        enemyMissilePool,
        poolManager.registerPool<EnemyProjectile>(200, ENEMY_PROJECTILE_SHOOT),
        poolManager.registerPool<Explosion>(40, ENEMY_MISSILE_EXPLODED),
        poolManager.registerPool<Sparkle>(100, ENEMY_SPARKLE_SPAWNED),
        poolManager.registerPool<RandomPickup>(20, PICKUP_ITEM_SPAWNED)
        );
}