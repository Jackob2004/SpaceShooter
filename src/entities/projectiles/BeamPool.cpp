#include "BeamPool.h"

BeamPool::BeamPool() {
    firstAvailable = &projectiles[0];

    for (int i = 0; i < POOL_SIZE - 1; ++i) {
        projectiles[i].setNext(&projectiles[i + 1]);
    }

    projectiles[POOL_SIZE - 1].setNext(nullptr);
}

void BeamPool::create(const Vector2 spawnPoint) {
    if (firstAvailable == nullptr) return;

    const auto newProjectile = static_cast<BeamProjectile*>(firstAvailable);
    firstAvailable = newProjectile->getNext();

    newProjectile->init(spawnPoint);
}

void BeamPool::update() {
    for (auto & projectile : projectiles) {
        if (!projectile.isAlive()) continue;

        projectile.update();
        if (!projectile.isAlive()) {
            projectile.setNext(firstAvailable);
            firstAvailable = &projectile;
        }
    }
}

void BeamPool::render() {
    for (auto & projectile : projectiles) {
        projectile.render();
    }
}

BeamPool::~BeamPool() = default;