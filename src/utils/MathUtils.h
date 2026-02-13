#ifndef SPACESHOOTER_MATHUTILS_H
#define SPACESHOOTER_MATHUTILS_H
#include <raylib.h>

namespace MathUtils {
bool isInVerticalRange(Vector2 it, Vector2 targetPosition, float range);

bool isInHorizontalRange(Vector2 it, Vector2 targetPosition, float range);

int getRandomInRange(int from, int to);

Vector2 normalizeVector(Vector2 vector);

Vector2 subtrackVectors(Vector2 a, Vector2 b);

Vector2 scaleVector(Vector2 a, float scalar);
}

#endif //SPACESHOOTER_MATHUTILS_H