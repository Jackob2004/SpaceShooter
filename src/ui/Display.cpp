#include "Display.h"

Display::Display(const Rectangle destRect, const int sprites, const char* texturePath) :
    renderer(new SpriteRenderer(sprites, texturePath)),
    destRect(destRect) {
}

Display::~Display() {
    delete renderer;
}

void Display::render() const {
    DrawTexturePro(renderer->getTexture(), renderer->getSource(), destRect, {0, 0}, 0, WHITE);
}

SpriteRenderer* Display::getRenderer() const {
    return renderer;
}