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

    [[nodiscard]] virtual bool isAlive() const = 0;

    void setPosition(Vector2 newPosition);

    [[nodiscard]] Vector2 getPosition() const;

    [[nodiscard]] float getEntityWidth() const;

    [[nodiscard]] float getEntityHeight() const;

private:
    Rectangle destinationRect;
    std::unique_ptr<SpriteRenderer> spriteRenderer;
    Vector2 velocity;

protected:
    [[nodiscard]] SpriteRenderer* getRenderer() const;

    void setVelocity(Vector2 updatedVelocity);
};


#endif //SPACESHOOTER_ENTITY_H