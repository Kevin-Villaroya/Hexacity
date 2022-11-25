#include "House.h"

House::House(const sf::Vector3f& position) : Entity(position, sf::Vector2f(0, 0), TextureToolAnimation::house)
{}

void House::update(){

}

TypeEntity House::getType() const{
    return TypeEntity::house;
}