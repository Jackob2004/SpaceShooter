#ifndef SPACESHOOTER_SHELLENEMYSTATE_H
#define SPACESHOOTER_SHELLENEMYSTATE_H

class ShellEnemy;

class ShellEnemyState {
public:
    virtual ~ShellEnemyState() = default;

    virtual ShellEnemyState* update(ShellEnemy& shellEnemy) = 0;
};


#endif //SPACESHOOTER_SHELLENEMYSTATE_H