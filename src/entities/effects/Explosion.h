#ifndef SPACESHOOTER_EXPLOSION_H
#define SPACESHOOTER_EXPLOSION_H
#include "../Entity.h"
#include "entities/Damageable.h"


class Explosion : public Entity, public Damageable {
public:
    Explosion();

    void init(Vector2 spawnPoint) override;

    void update() override;

    void render() override;

    [[nodiscard]] bool isAlive() const override;

    void dealDamage(int damage) override;

    int getDamage() override;

private:
    static constexpr int FRAMES = 6;
    int timeLeft;
    int damage;
};


#endif //SPACESHOOTER_EXPLOSION_H