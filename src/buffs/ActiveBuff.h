#ifndef SPACESHOOTER_ACTIVEBUFF_H
#define SPACESHOOTER_ACTIVEBUFF_H
class Player;

class ActiveBuff {
public:
    virtual ~ActiveBuff() = default;

    explicit ActiveBuff(float maxAliveTime);

    virtual bool update(Player& player);

private:
    const float maxTime;
    float timeAlive;
};


#endif //SPACESHOOTER_ACTIVEBUFF_H