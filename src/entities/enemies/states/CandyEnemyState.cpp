#include "CandyEnemyState.h"
#include "CandyAdvancingState.h"
#include "CandyTargetingState.h"
#include "CandyShootingState.h"
#include "CandyPausingState.h"

CandyAdvancingState CandyEnemyState::advancing;
CandyTargetingState CandyEnemyState::targeting;
CandyShootingState CandyEnemyState::shooting;
CandyPausingState CandyEnemyState::pausing;
