#ifndef SPACESHOOTER_EXPLOSION_H
#define SPACESHOOTER_EXPLOSION_H
#include "../Entity.h"


class Explosion : public Entity {
public:
    Explosion();

    void init(Vector2 spawnPoint) override;

    void update() override;

    void render() override;

    [[nodiscard]] bool isAlive() const override;

private:
    static constexpr int FRAMES = 6;
    int timeLeft;
};


#endif //SPACESHOOTER_EXPLOSION_H