#ifndef SPACESHOOTER_BEAMPROJECTILE_H
#define SPACESHOOTER_BEAMPROJECTILE_H

#include "Entity.h"

class BeamProjectile : public Entity {
    friend class BeamPool;

public:
    void init(Vector2 spawnPoint);

    void update() override;

    void render() override;

    static void initTexture();

    static void unloadTexture();

    [[nodiscard]] bool isAlive() const override;

private:
    BeamProjectile();

    bool alive;
    static Texture2D texture;
};


#endif //SPACESHOOTER_BEAMPROJECTILE_H