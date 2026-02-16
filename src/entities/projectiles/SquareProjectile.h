#ifndef SPACESHOOTER_SQUAREPROJECTILE_H
#define SPACESHOOTER_SQUAREPROJECTILE_H
#include "entities/Entity.h"
#include <unordered_set>

class SquareProjectile : public Entity {
public:
    SquareProjectile();

    void init(Vector2 spawnPoint) override;

    void update() override;

    void render() override;

    [[nodiscard]] bool isAlive() const override;

    void takeDamage(int damage) override;

    int getDamage(Damageable* target) override;

private:
    bool alive;
    std::unordered_set<Damageable*> damaged;
};


#endif //SPACESHOOTER_SQUAREPROJECTILE_H