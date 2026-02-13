#include "KamikazeTargetingState.h"

#include "KamikazeAdvancingState.h"
#include "KamikazeDyingState.h"
#include "entities/enemies/KamikazeEnemy.h"
#include "utils/MathUtils.h"

void KamikazeTargetingState::enter(KamikazeEnemy& kamikazeEnemy) {
    kamikazeEnemy.setVelocity({0, 0});
    kamikazeEnemy.setStateTime(100);
}

KamikazeEnemyState* KamikazeTargetingState::update(KamikazeEnemy& kamikazeEnemy) {
    if (kamikazeEnemy.getStateTime() < 0) {
        return &KamikazeEnemyState::advancing;
    }

    if (MathUtils::isInVerticalRange(kamikazeEnemy.getPosition(), kamikazeEnemy.getTarget()->getPosition(), 0.30)) {
        return &KamikazeTargetingState::dying;
    }

    return nullptr;
}