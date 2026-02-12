#ifndef SPACESHOOTER_ENEMYPROJECTILE_H
#define SPACESHOOTER_ENEMYPROJECTILE_H
#include "entities/Damageable.h"
#include "entities/Entity.h"


class EnemyProjectile : public Entity, public Damageable {
public:
    EnemyProjectile();

    void init(Vector2 spawnPoint) override;

    void update() override;

    void render() override;

    [[nodiscard]] bool isAlive() const override;

    void dealDamage(int damage) override;

    int getDamage() override;

private:
    bool alive;
};


#endif //SPACESHOOTER_ENEMYPROJECTILE_H