#ifndef SPACESHOOTER_SCOREUI_H
#define SPACESHOOTER_SCOREUI_H
#include <memory>

#include "DigitDisplay.h"
#include <vector>

#include "core/events/Observer.h"


class ScoreUI : public Observer<int> {
public:
    ScoreUI();

    void render() const;

    void update();

    void onNotify(const int& data, Event event) override;

private:
    static constexpr int DIGITS_IN_SCORE = 5;
    std::vector<std::unique_ptr<DigitDisplay> > digits;
    int maxScore;
    int currentScore;
    float timeSinceLastScoreUpdate;

    void resetScore() const;

    static std::vector<int> getIndividualDigits(int number);

    static void formatIndividualDigits(std::vector<int>& individualDigits);
};


#endif //SPACESHOOTER_SCOREUI_H