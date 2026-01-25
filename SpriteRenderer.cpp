#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer(const int totalSprites, const char *texturePath): totalSprites(totalSprites) {
    if (totalSprites < 1) throw std::invalid_argument("Total sprites must be at least 1");

    spritesheet = LoadTexture(texturePath);
    frameRect = {
        .x = 0,
        .y = 0,
        .width = static_cast<float>(spritesheet.width) / static_cast<float>(totalSprites),
        .height = static_cast<float>(spritesheet.height)
    };

    currentFrame = frameCounter = 0;
}

SpriteRenderer::~SpriteRenderer() {
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

Texture2D SpriteRenderer::getTexture() const {
    return spritesheet;
}

Rectangle SpriteRenderer::getSource() const {
    return frameRect;
}

