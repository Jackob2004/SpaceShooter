#ifndef SPACESHOOTER_HEALTHBARDISPLAY_H
#define SPACESHOOTER_HEALTHBARDISPLAY_H
#include "Display.h"
#include "core/events/Event.h"
#include "core/events/Observer.h"


class HealthBarDisplay : public Display, public Observer<Vector2> {
public:
    HealthBarDisplay();

private:
    static constexpr int TOTAL_SPRITES = 7;

    void onNotify(const Vector2& data, Event event) override;
};


#endif //SPACESHOOTER_HEALTHBARDISPLAY_H