#ifndef SPACESHOOTER_CANDYADVANCINGSTATE_H
#define SPACESHOOTER_CANDYADVANCINGSTATE_H

#include "CandyEnemyState.h"

class CandyAdvancingState : public CandyEnemyState {
public:

    void enter(CandyEnemy& candyEnemy) override;

    CandyEnemyState* update(CandyEnemy& candyEnemy) override;
};


#endif //SPACESHOOTER_CANDYADVANCINGSTATE_H