#include "GameOverDisplay.h"

#include "core/Game.h"

GameOverDisplay::GameOverDisplay() :
    Display({SCREEN_WIDTH / 2 - WIDTH / 2, SCREEN_HEIGHT / 2 - HEIGHT / 2, WIDTH, HEIGHT},
            2,
            "assets/ui/game_over.png") {
}

void GameOverDisplay::update() const {
    getRenderer()->advanceSprite();
}

void GameOverDisplay::onNotify(const Vector2& data, Event event) {
}