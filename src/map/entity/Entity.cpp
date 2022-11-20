#include "Entity.h"
Entity::Entity() :
Entity(sf::Vector2f(0, 0))
{}

Entity::Entity(const sf::Vector2f& position) :
Entity(position, TextureToolAnimation::EMPTY)
{}

Entity::Entity(const sf::Vector2f& position, const TextureToolAnimation& texture) :
Entity(position, sf::Vector2f(0, 0), texture)
{}

Entity::Entity(const sf::Vector2f& position, const sf::Vector2f& size, const TextureToolAnimation& texture) : 
position(position), size(size), sprite(texture)
{}