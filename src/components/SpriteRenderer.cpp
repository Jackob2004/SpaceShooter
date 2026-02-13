#include "SpriteRenderer.h"
#include <cassert>

SpriteRenderer::SpriteRenderer(const int totalSprites, const bool sharedTexture, const Texture2D& texture) :
    totalSprites(totalSprites),
    sharedTexture(sharedTexture),
    spritesheet(texture) {
    assert(totalSprites >= 1 && "Total sprites must be at least 1");

    frameRect = {
        .x = 0,
        .y = 0,
        .width = static_cast<float>(spritesheet.width) / static_cast<float>(totalSprites),
        .height = static_cast<float>(spritesheet.height)
    };

    currentFrame = frameCounter = 0;
}

SpriteRenderer::SpriteRenderer(const int totalSprites, const Texture2D& sharedTexture) :
    SpriteRenderer(totalSprites, true, sharedTexture) {
}

SpriteRenderer::SpriteRenderer(const int totalSprites, const char* texturePath) :
    SpriteRenderer(totalSprites, false, LoadTexture(texturePath)) {
}

SpriteRenderer::~SpriteRenderer() {
    if (sharedTexture) return;
    UnloadTexture(spritesheet);
}

void SpriteRenderer::advanceSprite() {
    frameCounter++;

    if (frameCounter >= (60 / FRAMES_SPEED)) {
        frameCounter = 0;
        currentFrame = (currentFrame + 1 < totalSprites) ? currentFrame + 1 : 0;
        frameRect.x = static_cast<float>(currentFrame) * frameRect.width;
    }
}

void SpriteRenderer::setSprite(const int spriteIndex) {
    assert(spriteIndex >= 0 && spriteIndex < totalSprites && "Invalid sprite index" );
    currentFrame = spriteIndex;
    frameRect.x = static_cast<float>(currentFrame) * frameRect.width;
}

Texture2D SpriteRenderer::getTexture() const {
    return spritesheet;
}

Rectangle SpriteRenderer::getSource() const {
    return frameRect;
}