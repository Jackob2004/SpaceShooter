#ifndef SPACESHOOTER_CANDYENEMYSTATES_H
#define SPACESHOOTER_CANDYENEMYSTATES_H
#include <raylib.h>

class CandyEnemy;
class CandyAdvancingState;
class CandyTargetingState;
class CandyShootingState;
class CandyPausingState;

class CandyEnemyState {
public:
    static CandyAdvancingState advancing;
    static CandyTargetingState targeting;
    static CandyShootingState shooting;
    static CandyPausingState pausing;

    virtual ~CandyEnemyState() = default;

    virtual CandyEnemyState* update(CandyEnemy& candyEnemy) = 0;

    virtual void enter(CandyEnemy& candyEnemy) = 0;
};


#endif //SPACESHOOTER_CANDYENEMYSTATES_H