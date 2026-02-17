#ifndef SPACESHOOTER_SHELLTRAILINGSTATE_H
#define SPACESHOOTER_SHELLTRAILINGSTATE_H
#include "ShellEnemyState.h"


class ShellTrailingState : public ShellEnemyState {
public:
    explicit ShellTrailingState();

    ShellEnemyState* update(ShellEnemy& shellEnemy) override;

    void enter(ShellEnemy& shellEnemy) override;

private:
    static constexpr int TRAILING_GAP = 60;
    float lastTrailingYPosition;
};


#endif //SPACESHOOTER_SHELLTRAILINGSTATE_H