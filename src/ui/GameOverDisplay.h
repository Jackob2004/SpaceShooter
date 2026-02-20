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
};


#endif //SPACESHOOTER_GAMEOVERDISPLAY_H