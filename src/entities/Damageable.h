#ifndef SPACESHOOTER_DAMAGEABLE_H
#define SPACESHOOTER_DAMAGEABLE_H


class Damageable {
public:
    virtual ~Damageable() = default;

    virtual void dealDamage(int damage) = 0;

    virtual int getDamage() = 0;

    virtual int getDamage(Damageable* target) {return 0;}
};


#endif //SPACESHOOTER_DAMAGEABLE_H