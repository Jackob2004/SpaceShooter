#ifndef SPACESHOOTER_SHIELDBUFF_H
#define SPACESHOOTER_SHIELDBUFF_H
#include "ActiveBuff.h"


class ShieldBuff : public ActiveBuff {
public:
    ShieldBuff();

    bool update(Player& player) override;

    void onDeactivate(Player& player) override;

private:
    float passedTime;
};


#endif //SPACESHOOTER_SHIELDBUFF_H