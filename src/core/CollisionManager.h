#ifndef SPACESHOOTER_COLLISIONMANAGER_H
#define SPACESHOOTER_COLLISIONMANAGER_H
#include <vector>

#include "entities/Player.h"
#include "entities/EntityPool.h"

class CollisionManager {
public:
    explicit CollisionManager(Player* player);

    template <typename... Pools>
    void registerEnemyPool(Pools... pools) {
        (enemies.push_back(pools), ...);
    }

    template <typename... Pools>
    void registerEnemyProjectilePool(Pools... pools) {
        (enemyProjectiles.push_back(pools), ...);
    }

    template <typename... Pools>
    void registerPlayerProjectilePool(Pools... pools) {
        (playerProjectiles.push_back(pools), ...);
    }

    void checkCollisions() const;

private:
    std::vector<IEntityPool*> enemies;
    std::vector<IEntityPool*> enemyProjectiles;
    std::vector<IEntityPool*> playerProjectiles;
    Player* player;
};


#endif //SPACESHOOTER_COLLISIONMANAGER_H