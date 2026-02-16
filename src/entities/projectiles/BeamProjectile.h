#ifndef SPACESHOOTER_BEAMPROJECTILE_H
#define SPACESHOOTER_BEAMPROJECTILE_H

#include "entities/Damageable.h"
#include "entities/Entity.h"

class BeamProjectile : public Entity {
public:
    BeamProjectile();

    void init(Vector2 spawnPoint) override;

    void update() override;

    void render() override;

    [[nodiscard]] bool isAlive() const override;

    void takeDamage(int damage) override;

    int getDamage(Damageable* target) override;

private:
    bool alive;
};


#endif //SPACESHOOTER_BEAMPROJECTILE_H