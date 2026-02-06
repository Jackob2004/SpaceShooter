#ifndef SPACESHOOTER_GAME_H
#define SPACESHOOTER_GAME_H
#include <memory>

#include "Player.h"
#include "SpriteRenderer.h"

constexpr static int SCREEN_WIDTH = 800;
constexpr static int SCREEN_HEIGHT = 600;
constexpr static int FPS = 60;

class Game: public Observer<Entity> {
public:
    Game();

    void processInput();

    void update();

    void render();

    void onNotify(Entity& data, Event event) override;

private:
    std::unique_ptr<SpriteRenderer> backgroundRenderer;
    Rectangle backgroundDestRect;
    Player player;
};


#endif //SPACESHOOTER_GAME_H