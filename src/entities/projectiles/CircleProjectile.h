#ifndef SPACESHOOTER_CIRCLEPROJECTILE_H
#define SPACESHOOTER_CIRCLEPROJECTILE_H
#include "entities/Entity.h"


class CircleProjectile : public Entity {
public:
    CircleProjectile();

    void init(Vector2 spawnPoint) override;

    void update() override;

    void render() override;

    [[nodiscard]] bool isAlive() const override;

    void takeDamage(int damage) override;

    int getDamage(Damageable* target) override;

private:
    float yVelocity;
    bool alive;
};


#endif //SPACESHOOTER_CIRCLEPROJECTILE_H