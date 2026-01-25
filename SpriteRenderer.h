#ifndef SPACESHOOTER_SPRITERENDERER_H
#define SPACESHOOTER_SPRITERENDERER_H

#include <raylib.h>
#include <stdexcept>

constexpr unsigned int FRAMES_SPEED = 4;

class SpriteRenderer {
    public:
        SpriteRenderer(int totalSprites, const char *texturePath);
        ~SpriteRenderer();
        void advanceSprite();
        [[nodiscard]] Texture2D getTexture() const;
        [[nodiscard]] Rectangle getSource() const;

    private:
        const unsigned int totalSprites;
        Texture2D spritesheet{};
        Rectangle frameRect{};
        unsigned int currentFrame;
        unsigned int frameCounter;
};


#endif //SPACESHOOTER_SPRITERENDERER_H