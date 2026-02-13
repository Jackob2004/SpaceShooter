//
// Created by admin on 2/13/26.
//

#ifndef SPACESHOOTER_KAMIKAZEDYINGSTATE_H
#define SPACESHOOTER_KAMIKAZEDYINGSTATE_H
#include "KamikazeEnemyState.h"


class KamikazeDyingState : public KamikazeEnemyState {
public:
    void enter(KamikazeEnemy& kamikazeEnemy) override;

    KamikazeEnemyState* update(KamikazeEnemy& kamikazeEnemy) override;
};


#endif //SPACESHOOTER_KAMIKAZEDYINGSTATE_H