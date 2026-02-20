#include "ScoreUI.h"

#include "core/Game.h"
#include <cassert>
#include <algorithm>

ScoreUI::ScoreUI() :
    maxScore(0),
    currentScore(0),
    timeSinceLastScoreUpdate(0) {
    constexpr int digitWidth = 20;
    constexpr int gap = 15;
    constexpr int margin = 10;
    constexpr int scoreWidth = digitWidth * DIGITS_IN_SCORE + (DIGITS_IN_SCORE - 1) * gap;
    constexpr int startPoint = SCREEN_WIDTH - scoreWidth - margin;

    for (int i = 0; i < DIGITS_IN_SCORE; i++) {
        int xPos = startPoint + i * (digitWidth + gap);
        digits.push_back(std::make_unique<DigitDisplay>(xPos, margin, digitWidth));
    }

    resetScore();
}

void ScoreUI::render() const {
    for (int i = 0; i < DIGITS_IN_SCORE; i++) {
        digits[i]->render();
    }
}

void ScoreUI::update() {
    timeSinceLastScoreUpdate += GetFrameTime();
    if (currentScore < maxScore && timeSinceLastScoreUpdate > 0.08f) {
        currentScore++;
        timeSinceLastScoreUpdate = 0;

        std::vector<int> individualDigits = getIndividualDigits(currentScore);
        formatIndividualDigits(individualDigits);

        for (int i = 0; i < DIGITS_IN_SCORE; i++) {
            digits[i]->setDigit(individualDigits[i]);
        }
    }
}

void ScoreUI::onNotify(const int& data, const Event event) {
    if (event != GAME_SCORE_UPDATED) return;

    maxScore = data;
}

void ScoreUI::resetScore() const {
    assert(digits.size() == DIGITS_IN_SCORE);

    for (int i = 0; i < DIGITS_IN_SCORE; i++) {
        digits[i]->setDigit(0);
    }
}

std::vector<int> ScoreUI::getIndividualDigits(int number) {
    std::vector<int> individualDigits;

    while (number != 0) {
        individualDigits.push_back(number % 10);
        number /= 10;
    }

    return individualDigits;
}

void ScoreUI::formatIndividualDigits(std::vector<int>& individualDigits) {
    while (individualDigits.size() != DIGITS_IN_SCORE) {
        individualDigits.push_back(0);
    }

    std::ranges::reverse(individualDigits);
}