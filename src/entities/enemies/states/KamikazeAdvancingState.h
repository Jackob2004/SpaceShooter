#ifndef SPACESHOOTER_KAMIKAZEADVANCINGSTATE_H
#define SPACESHOOTER_KAMIKAZEADVANCINGSTATE_H
#include "KamikazeEnemyState.h"


class KamikazeAdvancingState : public KamikazeEnemyState {
public:
    void enter(KamikazeEnemy& kamikazeEnemy) override;

    KamikazeEnemyState* update(KamikazeEnemy& kamikazeEnemy) override;
};


#endif //SPACESHOOTER_KAMIKAZEADVANCINGSTATE_H