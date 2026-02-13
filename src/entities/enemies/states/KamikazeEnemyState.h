#ifndef SPACESHOOTER_KAMIKAZEENEMYSTATE_H
#define SPACESHOOTER_KAMIKAZEENEMYSTATE_H

class KamikazeEnemy;
class KamikazeAdvancingState;
class KamikazeTargetingState;
class KamikazeDyingState;

class KamikazeEnemyState {
public:
    static KamikazeAdvancingState advancing;
    static KamikazeTargetingState targeting;
    static KamikazeDyingState dying;

    virtual ~KamikazeEnemyState() = default;

    virtual KamikazeEnemyState* update(KamikazeEnemy& kamikazeEnemy) = 0;

    virtual void enter(KamikazeEnemy& kamikazeEnemy) = 0;
};


#endif //SPACESHOOTER_KAMIKAZEENEMYSTATE_H