#ifndef SPACESHOOTER_DISPLAY_H
#define SPACESHOOTER_DISPLAY_H
#include <raylib.h>

#include "core/events/Observer.h"

class SpriteRenderer;

class Display : public Observer<Vector2> {
public:
    Display(Rectangle destRect, int sprites, const char* texturePath);

    ~Display() override;

    void render() const;

    [[nodiscard]] SpriteRenderer* getRenderer() const;

private:
    SpriteRenderer* renderer;
    Rectangle destRect;
};


#endif //SPACESHOOTER_DISPLAY_H