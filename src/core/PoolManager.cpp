#include "PoolManager.h"

void PoolManager::render() const {
    for (const auto& pool : pools) {
        pool->render();
    }
}

void PoolManager::update() const {
    for (const auto& pool : pools) {
        pool->update();
    }
}

IEntityPool* PoolManager::getPool(const Event associatedEvent) {
    const auto it = poolMap.find(associatedEvent);

    if (it == poolMap.end()) {
        return nullptr;
    }

    return it->second;
}