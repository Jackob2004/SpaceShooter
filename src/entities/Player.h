#ifndef SPACESHOOTER_PLAYER_H
#define SPACESHOOTER_PLAYER_H

#include <vector>
#include <memory>

#include "Damageable.h"
#include "Entity.h"
#include "core/events/Subject.h"

class Player : public Entity, public Subject<Vector2>, public Damageable {
public:
    Player(float playerWidth, float playerHeight, Vector2 spawPoint);

    void processInput();

    void update() override;

    void render() override;

    void init(Vector2 spawnPoint) override;

    [[nodiscard]] bool isAlive() const override;

    void dealDamage(int damage) override;

    int getDamage() override;

private:
    enum PlayerSprite {
        IDLE = 1,
        FLY_LEFT = 0,
        FLY_RIGHT = 2
    };

    PlayerSprite playerSprite;
    std::vector<std::unique_ptr<SpriteRenderer> > boosterRenderers;
    Rectangle boostersDestinationRect;
    int health;

    [[nodiscard]] Vector2 computeProjectilePosition() const;
};


#endif //SPACESHOOTER_PLAYER_H