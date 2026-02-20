#ifndef SPACESHOOTER_DIGITDISPLAY_H
#define SPACESHOOTER_DIGITDISPLAY_H
#include "Display.h"


class DigitDisplay : public Display {
public:
    DigitDisplay(float x, float y, float width);

    void setDigit(int digit) const;
};


#endif //SPACESHOOTER_DIGITDISPLAY_H