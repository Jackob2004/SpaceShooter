#ifndef SPACESHOOTER_SHELLENEMY_H
#define SPACESHOOTER_SHELLENEMY_H
#include "core/events/Subject.h"
#include "entities/Damageable.h"
#include "entities/Entity.h"
#include "states/ShellEnemyState.h"

class Player;

class ShellEnemy : public Entity,  public Subject<Vector2> {
    friend class ShellTrailingState;
    friend class ShellAdvancingState;
public:
    ShellEnemy();

    void update() override;

    void render() override;

    void init(Vector2 spawnPoint) override;

    [[nodiscard]] bool isAlive() const override;

    void takeDamage(int damage) override;

    int getDamage(Damageable* target) override;

    [[nodiscard]] Player* getTarget() const;

    void setTarget(Player* player);

    void setHealth(int updatedHealth);

private:
    Player* target = nullptr;
    int health;
    ShellEnemyState* state;
};


#endif //SPACESHOOTER_SHELLENEMY_H