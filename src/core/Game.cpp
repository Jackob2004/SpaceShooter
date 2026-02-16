#include "Game.h"

#include <iostream>

#include "items/MissileItem.h"

Game::Game() :
    backgroundRenderer(std::make_unique<SpriteRenderer>(2, "assets/background.png")),
    backgroundDestRect({0, 0, SCREEN_WIDTH, SCREEN_HEIGHT}),
    player(50, 50, {static_cast<float>(SCREEN_WIDTH) / 2 - 25, SCREEN_HEIGHT - 100}),
    beamPool(20),
    candyEnemyPool(20),
    enemyProjectilePool(100),
    enemyMissilePool(50),
    enemyExplosionPool(50),
    kamikazeEnemyPool(20),
    shellEnemyPool(20),
    enemySparklePool(100),
    pickupPool(20),
    playerMissilePool(20),
    playerExplosionPool(20) {
    player.addObserver(this);
    enemyMissilePool.forEachEntity([this](EnemyMissile& missile) {
        missile.addObserver(this);
    });
    candyEnemyPool.forEachEntity([this](CandyEnemy& enemy) {
        enemy.addObserver(this);
        enemy.setTarget(&player);
    });

    kamikazeEnemyPool.forEachEntity([this](KamikazeEnemy& enemy) {
        enemy.setTarget(&player);
    });

    shellEnemyPool.forEachEntity([this](ShellEnemy& enemy) {
        enemy.addObserver(this);
        enemy.setTarget(&player);
    });

    pickupPool.forEachEntity([this](RandomPickup& pickup) {
        pickup.addObserver(this);
    });

    playerMissilePool.forEachEntity([this](PlayerMissile& missile) {
        missile.addObserver(this);
    });

    candyEnemyPool.create({100, 1});
    pickupPool.create({200, 1});
}

void Game::processInput() {
    player.processInput();
}

// TODO refactor group them so one for loop ought be enough instead of adding update call every new pool
void Game::update() {
    backgroundRenderer->advanceSprite();
    player.update();
    beamPool.update();
    candyEnemyPool.update();
    enemyProjectilePool.update();
    enemyMissilePool.update();
    enemyExplosionPool.update();
    kamikazeEnemyPool.update();
    shellEnemyPool.update();
    enemySparklePool.update();
    pickupPool.update();
    playerMissilePool.update();
    playerExplosionPool.update();

    if (player.getPosition().x + player.getEntityHeight() > SCREEN_WIDTH) {
        player.setPosition({SCREEN_WIDTH - player.getEntityWidth(), SCREEN_HEIGHT - 100});
    } else if (player.getPosition().x < 0) {
        player.setPosition({0, SCREEN_HEIGHT - 100});
    }

    handleCollisions();
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
    kamikazeEnemyPool.render();
    shellEnemyPool.render();
    enemySparklePool.render();
    pickupPool.render();
    playerMissilePool.render();
    playerExplosionPool.render();
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
        case PLAYER_MISSILE_LAUNCHED:
            playerMissilePool.create(data);
            break;
        case PLAYER_MISSILE_EXPLODED:
            playerExplosionPool.create(data);
            break;
        case ENEMY_PROJECTILE_SHOOT:
            enemyProjectilePool.create(data);
            break;
        case ENEMY_MISSILE_LAUNCHED:
            enemyMissilePool.create(data);
            break;
        case ENEMY_MISSILE_EXPLODED:
            enemyExplosionPool.create(data);
            break;
        case ENEMY_SPARKLE_SPAWNED:
            enemySparklePool.create(data);
            break;
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

// TODO refactor move it to separate collision manager, making it more maintainable instead of adding new forEach every time you add new Damageable
void Game::handleCollisions() {
    beamPool.forEachActiveEntity([this](BeamProjectile& beam) {
        candyEnemyPool.forEachActiveEntity([&beam](CandyEnemy& enemy) {
            if (!beam.isAlive()) return;
            if (CheckCollisionRecs(beam.getHitBox(), enemy.getHitBox())) {
                beam.takeDamage(enemy.getDamage());
                enemy.takeDamage(beam.getDamage());
            }
        });
    });

    candyEnemyPool.forEachActiveEntity([this](CandyEnemy& enemy) {
        if (CheckCollisionRecs(player.getHitBox(), enemy.getHitBox())) {
            enemy.takeDamage(player.getDamage());
            player.takeDamage(enemy.getDamage());
        }
    });

    enemyProjectilePool.forEachActiveEntity([this](EnemyProjectile& projectile) {
        if (CheckCollisionRecs(player.getHitBox(), projectile.getHitBox())) {
            projectile.takeDamage(player.getDamage());
            player.takeDamage(projectile.getDamage());
        }
    });

    enemyExplosionPool.forEachActiveEntity([this](Explosion& explosion) {
        if (CheckCollisionRecs(player.getHitBox(), explosion.getHitBox())) {
            explosion.takeDamage(player.getDamage());
            player.takeDamage(explosion.getDamage(&player));
        }
    });

    kamikazeEnemyPool.forEachActiveEntity([this](KamikazeEnemy& enemy) {
        if (CheckCollisionRecs(player.getHitBox(), enemy.getHitBox())) {
            enemy.takeDamage(player.getDamage());
            player.takeDamage(enemy.getDamage());
        }
    });

    enemySparklePool.forEachActiveEntity([this](Sparkle& sparkle) {
        if (CheckCollisionRecs(player.getHitBox(), sparkle.getHitBox())) {
            player.takeDamage(sparkle.getDamage());
        }
    });

    pickupPool.forEachActiveEntity([this](RandomPickup& pickup) {
        if (CheckCollisionRecs(player.getHitBox(), pickup.getHitBox())) {
            pickup.takeDamage(player.getDamage());
        }
    });

    playerMissilePool.forEachActiveEntity([this](PlayerMissile& missile) {
        candyEnemyPool.forEachActiveEntity([&missile](CandyEnemy& enemy) {
            if (!missile.isAlive()) return;
            if (CheckCollisionRecs(missile.getHitBox(), enemy.getHitBox())) {
                missile.takeDamage(enemy.getDamage());
                enemy.takeDamage(missile.getDamage());
            }
        });
    });

    playerExplosionPool.forEachActiveEntity([this](Explosion& explosion) {
        candyEnemyPool.forEachActiveEntity([&explosion](CandyEnemy& enemy) {
            if (!explosion.isAlive()) return;
            if (CheckCollisionRecs(explosion.getHitBox(), enemy.getHitBox())) {
                explosion.takeDamage(enemy.getDamage());
                enemy.takeDamage(explosion.getDamage(&enemy));
            }
        });
    });
}