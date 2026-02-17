#ifndef SPACESHOOTER_GAMESTARTDISPLAY_H
#define SPACESHOOTER_GAMESTARTDISPLAY_H
#include "Display.h"
#include "core/events/Subject.h"


class GameStartDisplay : public Display, public Subject<Vector2> {
public:
    GameStartDisplay();

    void processInput();

    void update();

private:
    static constexpr float WIDTH = 400;
    static constexpr float HEIGHT = 100;

    void onNotify(const Vector2& data, Event event) override;
};


#endif //SPACESHOOTER_GAMESTARTDISPLAY_H