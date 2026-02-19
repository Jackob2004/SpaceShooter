#ifndef SPACESHOOTER_SPEEDBUFF_H
#define SPACESHOOTER_SPEEDBUFF_H
#include "ActiveBuff.h"


class SpeedBuff : public ActiveBuff {
public:
    SpeedBuff();

    bool update(Player& player) override;

    void onDeactivate(Player& player) override;

private:
    static constexpr int MAX_ALIVE = 10;
    int speed;
};


#endif //SPACESHOOTER_SPEEDBUFF_H