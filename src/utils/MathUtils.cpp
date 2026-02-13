#include "MathUtils.h"
#include <cmath>
#include <cassert>
#include <random>

#include "core/Game.h"

namespace MathUtils {
bool isInRange(const Vector2 it, const Vector2 targetPosition, const float range) {
    assert(range < 1.0 && range > 0.0 && "Range must be between 0 and 1");
    return std::abs(targetPosition.x - it.x) <= (SCREEN_WIDTH * range);
}

int getRandomInRange(const int from, const int to) {
    assert(from < to && "from must be smaller than to");
    static std::random_device rd; // obtain seed
    static std::mt19937 gen(rd());

    std::uniform_int_distribution distrib(from, to);

    return distrib(gen);
}
}