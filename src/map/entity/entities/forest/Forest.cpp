#include "Forest.h"

Forest::Forest(const sf::Vector3f& position) : Entity(position, sf::Vector2f(0, 0), TextureToolAnimation::forest)
{}

void Forest::update(){

}

TypeEntity Forest::getType() const{
    return TypeEntity::forest;
}