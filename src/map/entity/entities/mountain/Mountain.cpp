#include "Mountain.h"

Mountain::Mountain(const sf::Vector3f& position) : Entity(position, sf::Vector2f(1, 1), TextureToolAnimation::mountain)
{}

void Mountain::update(){

}

TypeEntity Mountain::getType() const{
    return TypeEntity::mountain;
}