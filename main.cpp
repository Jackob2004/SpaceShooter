#include <iostream>

#include "Game.h"

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Space Shooter");
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

    CloseWindow();
    return 0;
}