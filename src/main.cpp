#include <iostream>

#include "core/Game.h"
#include "core/TextureManager.h"

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Space Shooter");

    {
        Game game;

        SetTargetFPS(FPS);

        while (!WindowShouldClose()) {
            game.processInput();
            game.update();

            BeginDrawing();
            ClearBackground(RAYWHITE);
            game.render();
            EndDrawing();
        }
    }

    TextureManager::unloadTextures();
    CloseWindow();
    return 0;
}