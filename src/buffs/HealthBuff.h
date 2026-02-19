#ifndef SPACESHOOTER_HEALTHBUFF_H
#define SPACESHOOTER_HEALTHBUFF_H
#include "ActiveBuff.h"


class HealthBuff : public ActiveBuff {
public:
    HealthBuff();

    bool update(Player& player) override;

    void onDeactivate(Player& player) override;

private:
    static constexpr int REGENERATION_RATE = 1;
};


#endif //SPACESHOOTER_HEALTHBUFF_H