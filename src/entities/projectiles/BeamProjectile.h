#ifndef SPACESHOOTER_BEAMPROJECTILE_H
#define SPACESHOOTER_BEAMPROJECTILE_H

#include "entities/Entity.h"

class BeamProjectile : public Entity {
    friend class BeamPool;

public:
    void init(Vector2 spawnPoint);

    void update() override;

    void render() override;

    [[nodiscard]] bool isAlive() const override;

private:
    BeamProjectile();

    bool alive;
};


#endif //SPACESHOOTER_BEAMPROJECTILE_H