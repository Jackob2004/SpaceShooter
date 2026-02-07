#ifndef SPACESHOOTER_SPRITERENDERER_H
#define SPACESHOOTER_SPRITERENDERER_H

#include <raylib.h>
#include <stdexcept>

constexpr unsigned int FRAMES_SPEED = 4;

class SpriteRenderer {
public:
    SpriteRenderer(int totalSprites, const char* texturePath);

    SpriteRenderer(int totalSprites, const Texture2D& sharedTexture);

    ~SpriteRenderer();

    void advanceSprite();

    void setSprite(int spriteIndex);

    [[nodiscard]] Texture2D getTexture() const;

    [[nodiscard]] Rectangle getSource() const;

private:
    SpriteRenderer(int totalSprites, bool sharedTexture, const Texture2D& texture);

    const unsigned int totalSprites;
    bool sharedTexture;
    Texture2D spritesheet{};
    Rectangle frameRect{};
    unsigned int currentFrame;
    unsigned int frameCounter;
};


#endif //SPACESHOOTER_SPRITERENDERER_H