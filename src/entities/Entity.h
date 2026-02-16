#ifndef SPACESHOOTER_ENTITY_H
#define SPACESHOOTER_ENTITY_H

#include "Damageable.h"
#include "components/SpriteRenderer.h"

class Entity : public Damageable{
public:
    Entity(Rectangle destinationRect, SpriteRenderer* renderer, Vector2 velocity);

    ~Entity() override;

    virtual void update();

    virtual void render();

    virtual void init(Vector2 spawnPoint) = 0;

    [[nodiscard]] virtual bool isAlive() const = 0;

    [[nodiscard]] Entity* getNext() const;

    void setNext(Entity* next);

    void setPosition(Vector2 newPosition);

    [[nodiscard]] Vector2 getPosition() const;

    void setVelocity(Vector2 updatedVelocity);

    [[nodiscard]] Vector2 getVelocity() const;

    [[nodiscard]] float getEntityWidth() const;

    [[nodiscard]] float getEntityHeight() const;

    [[nodiscard]] Rectangle getHitBox() const;

    int getDamage(Damageable* target) override { return 0; }

    void takeDamage(int damage) override {}

private:
    union {
        struct {
            Rectangle destinationRect;
            SpriteRenderer* spriteRenderer;
            Vector2 velocity;
        };

        Entity* next;
    };

protected:
    [[nodiscard]] SpriteRenderer* getRenderer() const;
};


#endif //SPACESHOOTER_ENTITY_H