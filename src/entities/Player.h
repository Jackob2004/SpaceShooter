#ifndef SPACESHOOTER_PLAYER_H
#define SPACESHOOTER_PLAYER_H

#include <vector>
#include <memory>

#include "Damageable.h"
#include "Entity.h"
#include "buffs/ActiveBuff.h"
#include "core/events/Subject.h"
#include "items/Item.h"

class Player : public Entity, public Subject<Vector2> {
    friend class MissileItem;
    friend class SquareItem;
    friend class CircleItem;
    friend class HealthBuff;
public:
    Player(float playerWidth, float playerHeight, Vector2 spawPoint);

    void processInput();

    void update() override;

    void render() override;

    void init(Vector2 spawnPoint) override;

    [[nodiscard]] bool isAlive() const override;

    void takeDamage(int damage) override;

    int getDamage(Damageable* target) override;

    void equipItem(Item* newItem);

    void activateBuff(ActiveBuff* buff);

    [[nodiscard]] int getHealth() const;

    void setHealth(int updatedHealth);

    void setTakenDamageModifier(float modifier);

    void setSpeed(float updatedSpeed);

    [[nodiscard]] float getSpeed() const;

private:
    enum PlayerSprite {
        IDLE = 1,
        FLY_LEFT = 0,
        FLY_RIGHT = 2
    };

    static constexpr float PLAYER_SPEED = 100;
    static constexpr int PLAYER_HEALTH = 500;
    PlayerSprite playerSprite;
    std::vector<std::unique_ptr<SpriteRenderer> > boosterRenderers;
    Rectangle boostersDestinationRect;
    int health;
    float speed;
    float takenDamageModifier;
    Item* item;
    ActiveBuff* activeBuff;

    [[nodiscard]] Vector2 computeProjectilePosition() const;
    void unequipItem();
    void deactivateBuff();
};


#endif //SPACESHOOTER_PLAYER_H