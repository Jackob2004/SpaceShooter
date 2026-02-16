#ifndef SPACESHOOTER_IENTITYPOOL_H
#define SPACESHOOTER_IENTITYPOOL_H
#include <raylib.h>


class IEntityPool {
public:
    virtual ~IEntityPool() = default;

    virtual void create(Vector2 spawnPoint) = 0;

    virtual void update() = 0;

    virtual void render() = 0;

    virtual void forEachActiveEntity(std::function<void(Entity&)> func) = 0;
};


#endif //SPACESHOOTER_IENTITYPOOL_H