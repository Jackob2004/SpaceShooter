#ifndef SPACESHOOTER_HELDITEMDISPLAY_H
#define SPACESHOOTER_HELDITEMDISPLAY_H
#include <raylib.h>

#include "Display.h"
#include "core/events/Observer.h"

class HeldItemDisplay : public Display, public Observer<Vector2> {
public:
    HeldItemDisplay();

private:
    void onNotify(const Vector2& data, Event event) override;
};


#endif //SPACESHOOTER_HELDITEMDISPLAY_H