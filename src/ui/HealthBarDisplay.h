#ifndef SPACESHOOTER_HEALTHBARDISPLAY_H
#define SPACESHOOTER_HEALTHBARDISPLAY_H
#include "Display.h"


class HealthBarDisplay : public Display {
public:
    HealthBarDisplay();

private:
    static constexpr int TOTAL_SPRITES = 7;

    void onNotify(const Vector2& data, Event event) override;
};


#endif //SPACESHOOTER_HEALTHBARDISPLAY_H