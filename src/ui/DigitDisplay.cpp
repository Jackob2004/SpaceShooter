#include "DigitDisplay.h"

DigitDisplay::DigitDisplay(const float x, const float y, const float width) :
    Display({x, y, width, 40}, 10, "assets/ui/numbers.png") {
}

void DigitDisplay::setDigit(const int digit) const {
    getRenderer()->setSprite(digit);
}