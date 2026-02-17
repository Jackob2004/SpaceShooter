#ifndef SPACESHOOTER_GAME_H
#define SPACESHOOTER_GAME_H
#include <memory>

#include "CollisionManager.h"
#include "PoolManager.h"
#include "WavesManager.h"
#include "entities/Player.h"
#include "components/SpriteRenderer.h"

constexpr static int SCREEN_WIDTH = 800;
constexpr static int SCREEN_HEIGHT = 600;
constexpr static int FPS = 60;

class Game : public Observer<Vector2> {
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
    PoolManager poolManager;
    CollisionManager collisionManager;
    WavesManager wavesManager;

    void initPlayerProjectilePools();

    void initEnemyPools();

    void initEnemyProjectilePools();
};


#endif //SPACESHOOTER_GAME_H