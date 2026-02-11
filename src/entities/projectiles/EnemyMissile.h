#ifndef SPACESHOOTER_ENEMYMISSILE_H
#define SPACESHOOTER_ENEMYMISSILE_H
#include "core/events/Subject.h"
#include "entities/Entity.h"

class EnemyMissile : public Entity, public Subject<Vector2> {
public:
    EnemyMissile();

    void init(Vector2 spawnPoint) override;

    void update() override;

    void render() override;

    [[nodiscard]] bool isAlive() const override;

private:
    bool alive;
    static constexpr float AMPLITUDE = 20;
    static constexpr float FREQUENCY = 4;
    static constexpr float VELOCITY_Y = 100;
    float lifeTime = 0;
};


#endif //SPACESHOOTER_ENEMYMISSILE_H