#include "Entity.h"

Entity::Entity(const Rectangle destinationRect,
               std::unique_ptr<SpriteRenderer> renderer,
               const Vector2 velocity,
               const int health) :
    destinationRect(destinationRect),
    spriteRenderer(std::move(renderer)),
    velocity(velocity),
    health(health) {
    if (health < 1) throw std::invalid_argument("health must be greater than 0");
}

Entity::~Entity() = default;

void Entity::update() {
    destinationRect.x += velocity.x * GetFrameTime();
    destinationRect.y += velocity.y * GetFrameTime();
}

void Entity::render() {
    DrawTexturePro(spriteRenderer->getTexture(), spriteRenderer->getSource(), destinationRect, {0, 0}, 0.0f, WHITE);
}

bool Entity::isAlive() const {
    return health > 0;
}