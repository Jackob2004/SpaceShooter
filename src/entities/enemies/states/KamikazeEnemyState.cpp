#include "KamikazeEnemyState.h"

#include "KamikazeAdvancingState.h"
#include "KamikazeDyingState.h"
#include "KamikazeTargetingState.h"

KamikazeAdvancingState KamikazeEnemyState::advancing;
KamikazeTargetingState KamikazeEnemyState::targeting;
KamikazeDyingState KamikazeEnemyState::dying;