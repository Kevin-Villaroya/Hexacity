#include "Mountain.h"

Mountain::Mountain(const sf::Vector3f& position) : Entity(position, sf::Vector2f(0, 0), TextureToolAnimation::mountain)
{}

void Mountain::update(){

}

TypeEntity Mountain::getType() const{
    return TypeEntity::mountain;
}