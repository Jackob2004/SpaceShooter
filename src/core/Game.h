#ifndef SPACESHOOTER_GAME_H
#define SPACESHOOTER_GAME_H
#include <memory>

#include "CollisionManager.h"
#include "PoolManager.h"
#include "WavesManager.h"
#include "entities/Player.h"
#include "components/SpriteRenderer.h"
#include "ui/GameOverDisplay.h"
#include "ui/GameStartDisplay.h"
#include "ui/HealthBarDisplay.h"
#include "ui/HeldItemDisplay.h"
#include "ui/ScoreUI.h"

constexpr static int SCREEN_WIDTH = 800;
constexpr static int SCREEN_HEIGHT = 600;
constexpr static int FPS = 60;

class Game : public Observer<Vector2>, Subject<int> {
public:
    Game();

    void processInput();

    void update();

    void render();

    static bool isOutOfVerticalBounds(Vector2 position);

    static bool isOutOfHorizontalBounds(Vector2 position);

    void onNotify(const Vector2& data, Event event) override;

private:
    enum GameState {
        MENU,
        PLAYING,
        GAME_OVER,
    };

    struct GameMethods {
        std::function<void()> processInput;
        std::function<void()> update;
        std::function<void()> render;
    };

    GameState state;
    GameMethods methods[3];
    std::unique_ptr<SpriteRenderer> backgroundRenderer;
    Rectangle backgroundDestRect;
    Player player;
    int score;
    PoolManager poolManager;
    CollisionManager collisionManager;
    WavesManager wavesManager;
    HeldItemDisplay heldItemDisplay;
    HealthBarDisplay healthBarDisplay;
    GameOverDisplay gameOverDisplay;
    GameStartDisplay gameStartDisplay;
    ScoreUI scoreUI;

    void initGamMethods();

    void initPlayerProjectilePools();

    void initEnemyPools();

    void initEnemyProjectilePools();
};


#endif //SPACESHOOTER_GAME_H