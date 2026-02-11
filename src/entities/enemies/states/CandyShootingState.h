#ifndef SPACESHOOTER_CANDYSHOOTINGSTATE_H
#define SPACESHOOTER_CANDYSHOOTINGSTATE_H
#include "CandyEnemyState.h"

class CandyShootingState : public CandyEnemyState {
public:
    void enter(CandyEnemy& candyEnemy) override;

    CandyEnemyState* update(CandyEnemy& candyEnemy) override;
};


#endif //SPACESHOOTER_CANDYSHOOTINGSTATE_H