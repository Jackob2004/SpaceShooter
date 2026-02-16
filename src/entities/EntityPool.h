#ifndef SPACESHOOTER_ENTITYPOOL_H
#define SPACESHOOTER_ENTITYPOOL_H

#include <functional>

#include "Entity.h"
#include "IEntityPool.h"

template <typename TObject>
class EntityPool : public IEntityPool {
public:
    explicit EntityPool(const int size) :
        size(size) {
        entities = new TObject[size];
        firstAvailable = &entities[0];

        for (int i = 0; i < size - 1; ++i) {
            entities[i].setNext(&entities[i + 1]);
        }

        entities[size - 1].setNext(nullptr);
    }

    ~EntityPool() override {
        delete[] entities;
    }

    void create(const Vector2 spawnPoint) override {
        if (firstAvailable == nullptr) return;

        Entity* entity = firstAvailable;
        firstAvailable = entity->getNext();

        entity->init(spawnPoint);
    }

    void update() override {
        for (int i = 0; i < size; i++) {
            TObject& entity = entities[i];
            if (!entity.isAlive()) continue;

            entity.update();
            if (!entity.isAlive()) {
                reclaim(entity);
            }
        }
    }

    void render() override {
        for (int i = 0; i < size; i++) {
            entities[i].render();
        }
    }

    void forEachEntity(std::function<void(TObject&)> func) {
        for (int i = 0; i < size; i++) {
            func(entities[i]);
        }
    }

    void forEachActiveEntity(std::function<void(Entity&)> func) override {
        for (int i = 0; i < size; i++) {
            if (entities[i].isAlive()) {
                func(entities[i]);

                if (!entities[i].isAlive()) {
                    reclaim(entities[i]);
                }
            }
        }
    }

private:
    const int size;
    TObject* entities;
    Entity* firstAvailable;

    void reclaim(TObject& entity) {
        entity.setNext(firstAvailable);
        firstAvailable = &entity;
    }
};

#endif //SPACESHOOTER_ENTITYPOOL_H