#ifndef SPACESHOOTER_RANDOMPOWERUP_H
#define SPACESHOOTER_RANDOMPOWERUP_H
#include "core/events/Event.h"
#include "core/events/Subject.h"
#include "entities/Entity.h"


class RandomPowerup : public Entity, public Subject<Vector2> {
public:
    RandomPowerup();

    void update() override;

    void render() override;

    void init(Vector2 spawnPoint) override;

    [[nodiscard]] bool isAlive() const override;

    int getDamage(Damageable* target) override;

    void takeDamage(int damage) override;

private:
    explicit RandomPowerup(int randomIndex);

    static constexpr Event POWERUPS[] = {
        SPEED_POWERUP_PICKED_UP,
        HEALTH_POWERUP_PICKED_UP,
        DAMAGE_POWERUP_PICKED_UP
    };

    int powerupIndex;
    bool alive;
};


#endif //SPACESHOOTER_RANDOMPOWERUP_H