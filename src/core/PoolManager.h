#ifndef SPACESHOOTER_POOLMANAGER_H
#define SPACESHOOTER_POOLMANAGER_H
#include <unordered_map>
#include <vector>
#include <memory>

#include "entities/EntityPool.h"
#include "entities/IEntityPool.h"
#include "events/Event.h"

class PoolManager {
public:
    template <typename TObject>
    EntityPool<TObject>* registerPool(int size, Event associatedEvent);

    void render() const;

    void update() const;

    IEntityPool* getPool(Event associatedEvent);

private:
    std::vector<std::unique_ptr<IEntityPool> > pools;
    std::unordered_map<Event, IEntityPool*> poolMap;
};

template <typename TObject>
EntityPool<TObject>* PoolManager::registerPool(int size, const Event associatedEvent) {
    auto pool = std::make_unique<EntityPool<TObject> >(size);
    EntityPool<TObject>* entityPool = pool.get();

    pools.push_back(std::unique_ptr<IEntityPool>(std::move(pool)));
    poolMap[associatedEvent] = entityPool;

    return entityPool;
}


#endif //SPACESHOOTER_POOLMANAGER_H