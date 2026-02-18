#include <iostream>

#include "core/Game.h"
#include "core/SoundManager.h"
#include "core/TextureManager.h"

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Space Shooter");
    InitAudioDevice();
    {
        Game game;
        SoundManager soundManager;

        SetTargetFPS(FPS);

        while (!WindowShouldClose()) {
            game.processInput();
            game.update();
            soundManager.update();

            BeginDrawing();
            ClearBackground(RAYWHITE);
            game.render();
            EndDrawing();
        }
    }

    TextureManager::unloadTextures();
    CloseAudioDevice();
    CloseWindow();
    return 0;
}