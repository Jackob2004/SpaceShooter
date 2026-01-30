#ifndef SPACESHOOTER_PLAYER_H
#define SPACESHOOTER_PLAYER_H

#include <vector>

#include "Entity.h"

class Player : public Entity {
public:
    Player(float playerWidth, float playerHeight, Vector2 spawPoint);

    void processInput();

    void update() override;

    void render() override;

    void setPosition(Vector2 newPosition);

    [[nodiscard]] Vector2 getPosition() const;

    [[nodiscard]] float getPlayerWidth() const;

    [[nodiscard]] float getPlayerHeight() const;

private:
    enum PlayerSprite {
        IDLE = 1,
        FLY_LEFT = 0,
        FLY_RIGHT = 2
    };

    PlayerSprite playerSprite;
    std::vector<std::unique_ptr<SpriteRenderer>> boosterRenderers;
    Rectangle boostersDestinationRect;
};


#endif //SPACESHOOTER_PLAYER_H