#ifndef SPACESHOOTER_KAMIKAZEENEMY_H
#define SPACESHOOTER_KAMIKAZEENEMY_H
#include "entities/Damageable.h"
#include "entities/Entity.h"
#include "entities/Player.h"
#include "states/KamikazeEnemyState.h"


class KamikazeEnemy : public Entity  {
public:
    KamikazeEnemy();

    void update() override;

    void render() override;

    void init(Vector2 spawnPoint) override;

    [[nodiscard]] bool isAlive() const override;

    void takeDamage(int damage) override;

    int getDamage(Damageable* target) override;

    void setStateTime(int time);

    [[nodiscard]] int getStateTime() const;

    [[nodiscard]] Player* getTarget() const;

    void setTarget(Player* target);

    void setHealth(int health);

private:
    Player* target = nullptr;
    KamikazeEnemyState *state;
    int health;
    int stateTimeLeft;
};


#endif //SPACESHOOTER_KAMIKAZEENEMY_H