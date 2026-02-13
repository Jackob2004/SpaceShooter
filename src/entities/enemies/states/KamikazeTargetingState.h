#ifndef SPACESHOOTER_KAMIKAZETARGETINGSTATE_H
#define SPACESHOOTER_KAMIKAZETARGETINGSTATE_H
#include "KamikazeEnemyState.h"


class KamikazeTargetingState : public KamikazeEnemyState {
public:
    void enter(KamikazeEnemy& kamikazeEnemy) override;

    KamikazeEnemyState* update(KamikazeEnemy& kamikazeEnemy) override;
};


#endif //SPACESHOOTER_KAMIKAZETARGETINGSTATE_H