#include "Entity.h"

Entity::Entity(const Rectangle destinationRect,
               SpriteRenderer* renderer,
               const Vector2 velocity) :
    destinationRect(destinationRect),
    spriteRenderer(renderer),
    velocity(velocity) {
}

Entity::~Entity() {
    delete spriteRenderer;
}

void Entity::update() {
    destinationRect.x += velocity.x * GetFrameTime();
    destinationRect.y += velocity.y * GetFrameTime();
}

void Entity::render() {
    DrawTexturePro(spriteRenderer->getTexture(), spriteRenderer->getSource(), destinationRect, {0, 0}, 0.0f, WHITE);
}

Entity* Entity::getNext() const {
    return next;
}

void Entity::setNext(Entity* next) {
    this->next = next;
}

void Entity::setVelocity(const Vector2 updatedVelocity) {
    velocity.x = updatedVelocity.x;
    velocity.y = updatedVelocity.y;
}

Vector2 Entity::getVelocity() const {
    return velocity;
}

SpriteRenderer* Entity::getRenderer() const {
    return spriteRenderer;
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