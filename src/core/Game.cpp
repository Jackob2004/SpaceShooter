#include "Game.h"

#include <iostream>

#include "buffs/HealthBuff.h"
#include "buffs/ShieldBuff.h"
#include "buffs/SpeedBuff.h"
#include "items/MissileItem.h"
#include "entities/effects/Explosion.h"
#include "entities/effects/Sparkle.h"
#include "entities/enemies/KamikazeEnemy.h"
#include "entities/enemies/ShellEnemy.h"
#include "entities/pickups/RandomPickup.h"
#include "entities/projectiles/BeamProjectile.h"
#include "entities/projectiles/CircleProjectile.h"
#include "entities/projectiles/EnemyProjectile.h"
#include "entities/projectiles/EnemyMissile.h"
#include "entities/projectiles/PlayerMissile.h"
#include "entities/projectiles/SquareProjectile.h"
#include "entities/enemies/CandyEnemy.h"
#include "entities/powerups/RandomPowerup.h"
#include "items/CircleItem.h"
#include "items/SquareItem.h"
#include "utils/MathUtils.h"

Game::Game() :
    state(MENU),
    backgroundRenderer(std::make_unique<SpriteRenderer>(2, "assets/background.png")),
    backgroundDestRect({0, 0, SCREEN_WIDTH, SCREEN_HEIGHT}),
    player(50, 50, {static_cast<float>(SCREEN_WIDTH) / 2 - 25, SCREEN_HEIGHT - 100}),
    score(0),
    collisionManager(CollisionManager(&player)) {
    player.addObserver(this);
    player.addObserver(&heldItemDisplay);
    player.addObserver(&healthBarDisplay);
    this->addObserver(&scoreUI);
    wavesManager.addObserver(this);
    gameStartDisplay.addObserver(this);

    initPlayerProjectilePools();
    initEnemyPools();
    initEnemyProjectilePools();
    wavesManager.startWavesDispatch();
    initGamMethods();
}

void Game::processInput() {
    methods[state].processInput();
}

void Game::update() {
    methods[state].update();
}

void Game::render() {
    methods[state].render();
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
            player.equipItem(new MissileItem);
            break;
        case SQUARED_ITEM_PICKED_UP:
            player.equipItem(new SquareItem);
            break;
        case CIRCLE_ITEM_PICKED_UP:
            player.equipItem(new CircleItem);
            break;
        case HEALTH_POWERUP_PICKED_UP:
            player.activateBuff(new HealthBuff);
            break;
        case SPEED_POWERUP_PICKED_UP:
            player.activateBuff(new SpeedBuff);
            break;
        case SHIELD_POWERUP_PICKED_UP:
            player.activateBuff(new ShieldBuff);
            break;
        case PLAYER_DIED:
            state = GAME_OVER;
            break;
        case GAME_STARTED:
            state = PLAYING;
            break;
        case ENEMY_KILLED:
            score+= 5;
            notify(score, GAME_SCORE_UPDATED);
            break;
        default:
            break;
    }
}

void Game::initGamMethods() {
    methods[MENU] = {
        .processInput = [this]() {
            gameStartDisplay.processInput();
        },

        .update = [this]() {
            backgroundRenderer->advanceSprite();
            gameStartDisplay.update();
        },

        .render = [this]() {
            DrawTexturePro(backgroundRenderer->getTexture(),
                           backgroundRenderer->getSource(),
                           backgroundDestRect,
                           {0, 0},
                           0.0f,
                           WHITE);
            gameStartDisplay.render();
        }
    };

    methods[PLAYING] = {
        .processInput = [this]() {
            player.processInput();
        },

        .update = [this]() {
            backgroundRenderer->advanceSprite();
            player.update();
            poolManager.update();

            if (player.getPosition().x + player.getEntityHeight() > SCREEN_WIDTH) {
                player.setPosition({SCREEN_WIDTH - player.getEntityWidth(), SCREEN_HEIGHT - 100});
            } else if (player.getPosition().x < 0) {
                player.setPosition({0, SCREEN_HEIGHT - 100});
            }

            collisionManager.checkCollisions();
            wavesManager.update();
            scoreUI.update();
        },

        .render = [this]() {
            DrawTexturePro(backgroundRenderer->getTexture(),
                           backgroundRenderer->getSource(),
                           backgroundDestRect,
                           {0, 0},
                           0.0f,
                           WHITE);
            player.render();
            poolManager.render();
            heldItemDisplay.render();
            healthBarDisplay.render();
            scoreUI.render();
        }
    };

    methods[GAME_OVER] = {
        .processInput = []() {
        },

        .update = [this]() {
            backgroundRenderer->advanceSprite();
            gameOverDisplay.update();
        },

        .render = [this]() {
            DrawTexturePro(backgroundRenderer->getTexture(),
                           backgroundRenderer->getSource(),
                           backgroundDestRect,
                           {0, 0},
                           0.0f,
                           WHITE);
            gameOverDisplay.render();
        }
    };
}

void Game::initPlayerProjectilePools() {
    EntityPool<PlayerMissile>* missilePool = poolManager.registerPool<PlayerMissile>(10, PLAYER_MISSILE_LAUNCHED);
    missilePool->forEachEntity([this](PlayerMissile& missile) {
        missile.addObserver(this);
    });

    collisionManager.registerPlayerProjectilePool(
        missilePool,
        poolManager.registerPool<Explosion>(10, PLAYER_MISSILE_EXPLODED),
        poolManager.registerPool<BeamProjectile>(20, PLAYER_BEAM_SHOOT),
        poolManager.registerPool<SquareProjectile>(20, PLAYER_SQUARED_PROJECTILE_SHOOT),
        poolManager.registerPool<CircleProjectile>(20, PLAYER_CIRCLE_PROJECTILE_SHOOT)
        );
}

void Game::initEnemyPools() {
    EntityPool<CandyEnemy>* candyPool = poolManager.registerPool<CandyEnemy>(40, CANDY_ENEMY_SPAWNED);
    candyPool->forEachEntity([this](CandyEnemy& enemy) {
        enemy.addObserver(this);
        enemy.addObserver(&wavesManager);
        enemy.setTarget(&player);
    });

    EntityPool<KamikazeEnemy>* kamikazePool = poolManager.registerPool<KamikazeEnemy>(40, KAMIKAZE_ENEMY_SPAWNED);
    kamikazePool->forEachEntity([this](KamikazeEnemy& enemy) {
        enemy.addObserver(this);
        enemy.addObserver(&wavesManager);
        enemy.setTarget(&player);
    });

    EntityPool<ShellEnemy>* shellPool = poolManager.registerPool<ShellEnemy>(40, SHELL_ENEMY_SPAWNED);
    shellPool->forEachEntity([this](ShellEnemy& enemy) {
        enemy.addObserver(&wavesManager);
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

    EntityPool<RandomPickup>* pickupPool = poolManager.registerPool<RandomPickup>(20, PICKUP_ITEM_SPAWNED);
    pickupPool->forEachEntity([this](RandomPickup& pickup) {
        pickup.addObserver(this);
        pickup.addObserver(&heldItemDisplay);
        pickup.addObserver(&wavesManager);
    });

    EntityPool<RandomPowerup>* powerupPool = poolManager.registerPool<RandomPowerup>(20, POWERUP_SPAWNED);
    powerupPool->forEachEntity([this](RandomPowerup& powerup) {
        powerup.addObserver(this);
        powerup.addObserver(&wavesManager);
    });

    collisionManager.registerEnemyProjectilePool(
        enemyMissilePool,
        pickupPool,
        powerupPool,
        poolManager.registerPool<EnemyProjectile>(200, ENEMY_PROJECTILE_SHOOT),
        poolManager.registerPool<Explosion>(40, ENEMY_MISSILE_EXPLODED),
        poolManager.registerPool<Sparkle>(100, ENEMY_SPARKLE_SPAWNED)
        );
}