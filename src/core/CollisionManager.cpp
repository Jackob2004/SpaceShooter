#include "CollisionManager.h"

CollisionManager::CollisionManager(Player* player) :
    player(player) {
}

void CollisionManager::checkCollisions() const {
    if (enemies.empty() || playerProjectiles.empty()) return;

    for (auto& pool : enemies) {
        pool->forEachActiveEntity([this](Entity& entity) {
            if (CheckCollisionRecs(entity.getHitBox(), player->getHitBox())) {
                entity.takeDamage(player->getDamage(&entity));
                player->takeDamage(entity.getDamage(player));
            }
        });
    }

    for (auto& pool : enemyProjectiles) {
        pool->forEachActiveEntity([this](Entity& projectile) {
            if (CheckCollisionRecs(projectile.getHitBox(), player->getHitBox())) {
                projectile.takeDamage(player->getDamage(&projectile));
                player->takeDamage(projectile.getDamage(player));
            }
        });
    }

    for (auto& playerPool : playerProjectiles) {
        for (auto& enemyPool : enemies) {
            playerPool->forEachActiveEntity([&enemyPool](Entity& playerProjectile) {
                enemyPool->forEachActiveEntity([&playerProjectile](Entity& enemy) {
                    if (!playerProjectile.isAlive()) return;
                    if (CheckCollisionRecs(playerProjectile.getHitBox(), enemy.getHitBox())) {
                        playerProjectile.takeDamage(enemy.getDamage(&playerProjectile));
                        enemy.takeDamage(playerProjectile.getDamage(&enemy));
                    }
                });
            });
        }
    }
}