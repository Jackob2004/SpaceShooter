#include "SoundManager.h"

SoundManager::SoundManager() :
    music(LoadMusicStream("sounds/game_melody_1.mp3")) {
    PlayMusicStream(music);
    constexpr float pan = 0.5f;
    constexpr float volume = 0.8f;

    SetMusicPan(music, pan);
    SetMusicVolume(music, volume);
}

void SoundManager::update() {
    UpdateMusicStream(music);
}