#ifndef SPACESHOOTER_GAMEOVERDISPLAY_H
#define SPACESHOOTER_GAMEOVERDISPLAY_H
#include "Display.h"


class GameOverDisplay : public Display {
public:
    GameOverDisplay();

    void update() const;

private:
    static constexpr float WIDTH = 400;
    static constexpr float HEIGHT = 100;

    void onNotify(const Vector2& data, Event event) override;
};


#endif //SPACESHOOTER_GAMEOVERDISPLAY_H