#include "ActiveBuff.h"
#include <raylib.h>

ActiveBuff::ActiveBuff(const float maxAliveTime) :
    maxTime(maxAliveTime),
    timeAlive(0) {
}

bool ActiveBuff::update(Player& player) {
    timeAlive += GetFrameTime();
    return timeAlive < maxTime;
}

float ActiveBuff::getTimeAlive() const {
    return timeAlive;
}