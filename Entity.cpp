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

void Entity::setVelocity(const Vector2 updatedVelocity) {
    velocity.x = updatedVelocity.x;
    velocity.y = updatedVelocity.y;
}

SpriteRenderer* Entity::getRenderer() const {
    return spriteRenderer.get();
}

void Entity::setPosition(const Vector2 newPosition) {
    destinationRect.x = newPosition.x;
    destinationRect.y = newPosition.y;
}

Vector2 Entity::getPosition() const {
    return {destinationRect.x, destinationRect.y};
}

float Entity::getEntityWidth() const {
    return destinationRect.width;
}

float Entity::getEntityHeight() const {
    return destinationRect.height;
}