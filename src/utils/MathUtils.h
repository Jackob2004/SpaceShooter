#ifndef SPACESHOOTER_MATHUTILS_H
#define SPACESHOOTER_MATHUTILS_H
#include <raylib.h>

namespace MathUtils {
bool isInRange(Vector2 it, Vector2 targetPosition, float range);

int getRandomInRange(int from, int to);
}

#endif //SPACESHOOTER_MATHUTILS_H