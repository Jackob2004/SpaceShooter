#ifndef SPACESHOOTER_PLAYER_H
#define SPACESHOOTER_PLAYER_H

#include <vector>
#include <memory>

#include "Entity.h"
#include "Subject.h"

class Player : public Entity, public Subject<Entity> {
public:
    Player(float playerWidth, float playerHeight, Vector2 spawPoint);

    void processInput();

    void update() override;

    void render() override;

    [[nodiscard]] bool isAlive() const override;

private:
    enum PlayerSprite {
        IDLE = 1,
        FLY_LEFT = 0,
        FLY_RIGHT = 2
    };

    PlayerSprite playerSprite;
    std::vector<std::unique_ptr<SpriteRenderer> > boosterRenderers;
    Rectangle boostersDestinationRect;
    unsigned int health;
};


#endif //SPACESHOOTER_PLAYER_H