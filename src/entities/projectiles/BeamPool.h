#ifndef SPACESHOOTER_BEAMPOOL_H
#define SPACESHOOTER_BEAMPOOL_H

#include "BeamProjectile.h"

class BeamPool {
public:
    BeamPool();

    ~BeamPool();

    void create(Vector2 spawnPoint);

    void render();

    void update();

private:
    static constexpr int POOL_SIZE = 20;
    BeamProjectile projectiles[POOL_SIZE];
    Entity* firstAvailable;
};


#endif //SPACESHOOTER_BEAMPOOL_H