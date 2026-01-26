#ifndef SPACESHOOTER_ENTITY_H
#define SPACESHOOTER_ENTITY_H

#include <memory>
#include "SpriteRenderer.h"

class Entity {
public:
    Entity(Rectangle destinationRect, std::unique_ptr<SpriteRenderer> renderer, Vector2 velocity, int health);

    virtual ~Entity();

    virtual void update();

    virtual void render();

    [[nodiscard]] bool isAlive() const;

protected:
    Rectangle destinationRect;
    std::unique_ptr<SpriteRenderer> spriteRenderer;
    Vector2 velocity;
    unsigned int health;
};


#endif //SPACESHOOTER_ENTITY_H