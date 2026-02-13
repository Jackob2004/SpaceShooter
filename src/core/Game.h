#ifndef SPACESHOOTER_GAME_H
#define SPACESHOOTER_GAME_H
#include <memory>

#include "entities/Player.h"
#include "components/SpriteRenderer.h"
#include "entities/projectiles/BeamProjectile.h"
#include "entities/EntityPool.h"
#include "entities/effects/Explosion.h"
#include "entities/enemies/CandyEnemy.h"
#include "entities/enemies/KamikazeEnemy.h"
#include "entities/projectiles/EnemyMissile.h"
#include "entities/projectiles/EnemyProjectile.h"

constexpr static int SCREEN_WIDTH = 800;
constexpr static int SCREEN_HEIGHT = 600;
constexpr static int FPS = 60;

class Game: public Observer<Vector2> {
public:
    Game();

    void processInput();

    void update();

    void render();

    static bool isOutOfVerticalBounds(Vector2 position);

    static bool isOutOfHorizontalBounds(Vector2 position);

    void onNotify(const Vector2& data, Event event) override;


private:
    std::unique_ptr<SpriteRenderer> backgroundRenderer;
    Rectangle backgroundDestRect;
    Player player;
    EntityPool<BeamProjectile> beamPool;
    EntityPool<CandyEnemy> candyEnemyPool;
    EntityPool<EnemyProjectile> enemyProjectilePool;
    EntityPool<EnemyMissile> enemyMissilePool;
    EntityPool<Explosion> enemyExplosionPool;
    EntityPool<KamikazeEnemy> kamikazeEnemyPool;

    void handleCollisions();
};


#endif //SPACESHOOTER_GAME_H