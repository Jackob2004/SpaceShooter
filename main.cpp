#include <iostream>

#include "Game.h"

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Space Shooter");
    BeamProjectile::initTexture();

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

    BeamProjectile::unloadTexture();
    CloseWindow();
    return 0;
}