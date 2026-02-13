#include "MathUtils.h"
#include <cmath>
#include <cassert>
#include <random>

#include "core/Game.h"

namespace MathUtils {
bool isInRange(const float it, const float targetPosition, const float range, const int maxRange) {
    assert(range < 1.0 && range > 0.0 && "Range must be between 0 and 1");
    return std::abs(targetPosition - it) <= static_cast<float>(maxRange) * range;
}

bool isInVerticalRange(const Vector2 it, const Vector2 targetPosition, const float range) {
    return isInRange(it.y, targetPosition.y, range, SCREEN_HEIGHT);
}

bool isInHorizontalRange(const Vector2 it, const Vector2 targetPosition, const float range) {
    return isInRange(it.x, targetPosition.x, range, SCREEN_WIDTH);
}

int getRandomInRange(const int from, const int to) {
    assert(from < to && "from must be smaller than to");
    static std::random_device rd; // obtain seed
    static std::mt19937 gen(rd());

    std::uniform_int_distribution distrib(from, to);

    return distrib(gen);
}

Vector2 normalizeVector(const Vector2 vector) {
    const float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);

    return {
        .x = vector.x / magnitude,
        .y = vector.y / magnitude
    };
}

Vector2 subtrackVectors(const Vector2 a, const Vector2 b) {
    return {
        .x = a.x - b.x,
        .y = a.y - b.y
    };
}

Vector2 scaleVector(const Vector2 a, const float scalar) {
    return {
        .x = a.x * scalar,
        .y = a.y * scalar
    };
}
}