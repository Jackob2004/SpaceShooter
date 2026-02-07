#ifndef SPACESHOOTER_ENTITY_H
#define SPACESHOOTER_ENTITY_H

#include "components/SpriteRenderer.h"

class Entity {
public:
    Entity(Rectangle destinationRect, SpriteRenderer *renderer, Vector2 velocity);

    virtual ~Entity();

    virtual void update();

    virtual void render();

    [[nodiscard]] virtual bool isAlive() const = 0;

    [[nodiscard]] Entity *getNext() const;

    void setNext(Entity *next);

    void setPosition(Vector2 newPosition);

    [[nodiscard]] Vector2 getPosition() const;

    [[nodiscard]] float getEntityWidth() const;

    [[nodiscard]] float getEntityHeight() const;

private:
    union {
        struct {
            Rectangle destinationRect;
            SpriteRenderer *spriteRenderer;
            Vector2 velocity;
        };
        Entity* next;
    };

protected:
    [[nodiscard]] SpriteRenderer* getRenderer() const;

    void setVelocity(Vector2 updatedVelocity);
};


#endif //SPACESHOOTER_ENTITY_H