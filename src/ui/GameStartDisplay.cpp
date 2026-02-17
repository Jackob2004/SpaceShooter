#include "GameStartDisplay.h"

#include <iostream>

#include "core/Game.h"

GameStartDisplay::GameStartDisplay() :
    Display({SCREEN_WIDTH / 2 - WIDTH / 2, SCREEN_HEIGHT / 2 - HEIGHT / 2, WIDTH, HEIGHT},
            2,
            "assets/ui/game_start.png") {
}

void GameStartDisplay::processInput() {
    if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {
        notify({0,0}, GAME_STARTED);
    }
}

void GameStartDisplay::update() {
    getRenderer()->advanceSprite();
}

void GameStartDisplay::onNotify(const Vector2& data, Event event) {
}