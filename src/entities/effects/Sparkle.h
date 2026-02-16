#ifndef SPACESHOOTER_SPARKLE_H
#define SPACESHOOTER_SPARKLE_H
#include "entities/Damageable.h"
#include "entities/Entity.h"


class Sparkle : public Entity {
public:
    Sparkle();

    void init(Vector2 spawnPoint) override;

    void update() override;

    void render() override;

    [[nodiscard]] bool isAlive() const override;

    void takeDamage(int damage) override;

    int getDamage(Damageable* target) override;

private:
    static constexpr int FRAMES = 5;
    static constexpr int DAMAGE_COOLDOWN = 60;
    int timeLeft;
    int updatesCounter;
};


#endif //SPACESHOOTER_SPARKLE_H