#ifndef SPACESHOOTER_EXPLOSION_H
#define SPACESHOOTER_EXPLOSION_H
#include "../Entity.h"
#include "entities/Damageable.h"
#include <unordered_set>


class Explosion : public Entity {
public:
    Explosion();

    void init(Vector2 spawnPoint) override;

    void update() override;

    void render() override;

    [[nodiscard]] bool isAlive() const override;

    void takeDamage(int damage) override;

    int getDamage(Damageable* target) override;

private:
    static constexpr int FRAMES = 6;
    std::unordered_set<Damageable*> damaged;
    int timeLeft;
};


#endif //SPACESHOOTER_EXPLOSION_H