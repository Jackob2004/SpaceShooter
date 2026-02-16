#ifndef SPACESHOOTER_RANDOMPICKUP_H
#define SPACESHOOTER_RANDOMPICKUP_H
#include "core/events/Subject.h"
#include "entities/Damageable.h"
#include "entities/Entity.h"


class RandomPickup : public Entity, public Subject<Vector2> {
public:
    RandomPickup();

    void init(Vector2 spawnPoint) override;

    void update() override;

    void render() override;

    [[nodiscard]] bool isAlive() const override;

    void takeDamage(int damage) override;

    int getDamage(Damageable* target) override;

private:
    explicit RandomPickup(int randomOption);

    struct Options {
        int textureIndex;
        Event event;
    };

    static constexpr Options options[] = {
        {0, CIRCLE_ITEM_PICKED_UP},
        {1, SQUARED_ITEM_PICKED_UP},
        {2, MISSILE_ITEM_PICKED_UP}
    };
    int randomOption;
    bool pickedUp;
};


#endif //SPACESHOOTER_RANDOMPICKUP_H