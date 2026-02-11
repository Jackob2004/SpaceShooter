#ifndef SPACESHOOTER_CANDYTARGETINGSTATE_H
#define SPACESHOOTER_CANDYTARGETINGSTATE_H
#include "CandyEnemyState.h"


class CandyTargetingState : public CandyEnemyState {
public:
    void enter(CandyEnemy& candyEnemy) override;

    CandyEnemyState* update(CandyEnemy& candyEnemy) override;
};


#endif //SPACESHOOTER_CANDYTARGETINGSTATE_H