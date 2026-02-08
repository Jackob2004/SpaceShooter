#ifndef SPACESHOOTER_ENTITYPOOL_H
#define SPACESHOOTER_ENTITYPOOL_H

#include "Entity.h"

template <typename TObject>
class EntityPool {
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

    ~EntityPool() {
        delete[] entities;
    }

    void create(const Vector2 spawnPoint) {
        if (firstAvailable == nullptr) return;

        Entity* entity = firstAvailable;
        firstAvailable = entity->getNext();

        entity->init(spawnPoint);
    }

    void update() {
        for (int i = 0; i < size; i++) {
            TObject& entity = entities[i];
            if (!entity.isAlive()) continue;

            entity.update();
            if (!entity.isAlive()) {
                entity.setNext(firstAvailable);
                firstAvailable = &entity;
            }
        }
    }

    void render() {
        for (int i = 0; i < size; i++) {
            entities[i].render();
        }
    }

private:
    const int size;
    TObject* entities;
    Entity* firstAvailable;
};

#endif //SPACESHOOTER_ENTITYPOOL_H