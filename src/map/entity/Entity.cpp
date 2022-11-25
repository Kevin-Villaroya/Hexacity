#include "Entity.h"

Entity::Entity(const sf::Vector3f& position) :
Entity(position, TextureToolAnimation::EMPTY)
{}

Entity::Entity(const sf::Vector3f& position, const TextureToolAnimation& texture) :
Entity(position, sf::Vector2f(0, 0), texture)
{}

Entity::Entity(const sf::Vector3f& position, const sf::Vector2f& size, const TextureToolAnimation& texture) : 
position(position), size(size), sprite(texture)
{}
 
const sf::Vector3f& Entity::getPosition() const{
    return this->position;
}

const sf::Vector2f& Entity::getSize() const{
    return size;
}

 void Entity::setSize(const sf::Vector2f& size){
    this->size = size;
 }

const AnimatedSprite& Entity::getSprite() const{
    return this->sprite;
}

AnimatedSprite& Entity::getSprite(){
    return this->sprite;
}