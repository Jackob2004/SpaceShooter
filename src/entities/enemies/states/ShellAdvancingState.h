#ifndef SPACESHOOTER_SHELLADVANCINGSTATE_H
#define SPACESHOOTER_SHELLADVANCINGSTATE_H
#include "ShellEnemyState.h"


class ShellAdvancingState : public ShellEnemyState {
public:
    explicit ShellAdvancingState(ShellEnemy& shellEnemy);

    ShellEnemyState* update(ShellEnemy& shellEnemy) override;

private:
    static constexpr int MAX_VELOCITY = 120;
    int currentVelocity;
};


#endif //SPACESHOOTER_SHELLADVANCINGSTATE_H