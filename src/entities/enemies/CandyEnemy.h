#ifndef SPACESHOOTER_CANDYENEMY_H
#define SPACESHOOTER_CANDYENEMY_H

#include "core/events/Subject.h"
#include "entities/Entity.h"
#include "entities/Player.h"
class CandyEnemyState;

class CandyEnemy : public Entity, public Subject<Vector2> {
    friend class CandyShootingState;
    friend class CandyTargetingState;

public:
    CandyEnemy();

    void update() override;

    void render() override;

    void init(Vector2 spawnPoint) override;

    void setTarget(Player* player);

    [[nodiscard]] bool isAlive() const override;

    void setStateTimeLeft(int time);

    [[nodiscard]] int getStateTimeLeft() const;

    void setState(CandyEnemyState* updatedState);

    void setHealth(int updatedHealth);

private:
    Player *target = nullptr;
    unsigned int health;
    CandyEnemyState* state;
    int stateTimeLeft;
};


#endif //SPACESHOOTER_CANDYENEMY_H