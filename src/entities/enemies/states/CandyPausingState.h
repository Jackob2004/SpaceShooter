#ifndef SPACESHOOTER_CANDYPAUSESTATE_H
#define SPACESHOOTER_CANDYPAUSESTATE_H
#include "CandyEnemyState.h"

class CandyPausingState : public CandyEnemyState {
public:
    void enter(CandyEnemy& candyEnemy) override;

    CandyEnemyState* update(CandyEnemy& candyEnemy) override;
};


#endif //SPACESHOOTER_CANDYPAUSESTATE_H