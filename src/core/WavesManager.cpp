#include "WavesManager.h"
#include "vector"
#include "algorithm"
#include <iostream>

#include "Game.h"
#include "utils/MathUtils.h"

WavesManager::WavesManager() :
    currentWave(0),
    enemiesInWave(0),
    pickupsInWave(0),
    leftInWave(0),
    timeSinceLastDispatch(0) {
}

void WavesManager::startWavesDispatch() {
    currentWave = 1;
    enemiesInWave = 2;
    leftInWave = enemiesInWave;
    populateWave();
    dispatchWave();
}

void WavesManager::stopWavesDispatch() {
    currentWave = 0;
}

void WavesManager::update() {
    timeSinceLastDispatch += GetFrameTime();
    if (currentWave != 0 && timeSinceLastDispatch > BREAK_BETWEEN_DISPATCH && !wave.empty()) {
        dispatchWave();
    }
}

void WavesManager::onNotify(const Vector2& data, const Event event) {
    if (currentWave == 0) return;
    if (event == ENEMY_KILLED ||  event == ENEMY_DIED || event == PICKUP_DIED) {
        leftInWave--;
        if (leftInWave == 0) {
            nextWave();
            populateWave();
            dispatchWave();
            std::cout << "NEXT WAVE! " << currentWave << std::endl;
        }
    }
}

void WavesManager::nextWave() {
    currentWave++;
    enemiesInWave *= DIFFICULTY_MODIFIER;
    pickupsInWave = enemiesInWave / PICKUP_TO_ENEMY;
    leftInWave = enemiesInWave + pickupsInWave;
}

void WavesManager::populateWave() {
    for (int i = 0; i < enemiesInWave; i++) {
        const int randomEnemy = MathUtils::getRandomInRange(0, 2);
        wave.push_back(ENEMY_SPAWN_OPTIONS[randomEnemy]);
    }

    for (int i = 0; i < pickupsInWave; i++) {
        wave.push_back(PICKUP_SPAWN_OPTION);
    }

    std::ranges::shuffle(wave, MathUtils::getRandomGenerator());
}

void WavesManager::dispatchWave() {
    const int gap = MathUtils::getRandomInRange(60, 120);
    const auto xStart = static_cast<float>(MathUtils::getRandomInRange(1, SCREEN_WIDTH / 4));

    Vector2 spawnPoint = {
        .x = xStart,
        .y = 1,
    };

    while (!wave.empty() && spawnPoint.x < SCREEN_WIDTH - gap) {
        notify(spawnPoint, wave.back());
        wave.pop_back();
        spawnPoint.x += gap;
    }
    timeSinceLastDispatch = 0;
}