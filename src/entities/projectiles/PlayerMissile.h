#ifndef SPACESHOOTER_PLAYERMISSILE_H
#define SPACESHOOTER_PLAYERMISSILE_H
#include "core/events/Subject.h"
#include "entities/Damageable.h"
#include "entities/Entity.h"

class PlayerMissile : public Entity,  public Subject<Vector2> {
public:
    PlayerMissile();

    void init(Vector2 spawnPoint) override;

    void update() override;

    void render() override;

    [[nodiscard]] bool isAlive() const override;

    void takeDamage(int damage) override;

    int getDamage(Damageable* target) override;

private:
    static constexpr float AMPLITUDE = 15;
    static constexpr float FREQUENCY = 5;
    static constexpr float VELOCITY_Y = -160;
    float lifeTime = 0;
    bool alive;
};


#endif //SPACESHOOTER_PLAYERMISSILE_H