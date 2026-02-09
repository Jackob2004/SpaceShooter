#ifndef SPACESHOOTER_GAME_H
#define SPACESHOOTER_GAME_H
#include <memory>

#include "entities/Player.h"
#include "components/SpriteRenderer.h"
#include "entities/projectiles/BeamProjectile.h"
#include "entities/EntityPool.h"
#include "entities/enemies/CandyEnemy.h"

constexpr static int SCREEN_WIDTH = 800;
constexpr static int SCREEN_HEIGHT = 600;
constexpr static int FPS = 60;

class Game: public Observer<Entity> {
public:
    Game();

    void processInput();

    void update();

    void render();

    static bool isOutOfBounds(Vector2 position);

    void onNotify(Entity& data, Event event) override;

private:
    std::unique_ptr<SpriteRenderer> backgroundRenderer;
    Rectangle backgroundDestRect;
    Player player;
    CandyEnemy enemy;
    EntityPool<BeamProjectile> beamPool;
    void spawnPlayerProjectile(const Entity& shooter);
};


#endif //SPACESHOOTER_GAME_H