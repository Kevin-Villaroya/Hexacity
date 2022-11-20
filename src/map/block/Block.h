#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "../biome/Biome.h"
#include "../../animation/AnimatedSprite.h"
#include "../../animation/AnimationBlock.h"
#include <SFML/System/Vector3.hpp>

class Block{
  private:
    sf::Vector3<float> position;

    unsigned int height;
    unsigned int temperature;
    unsigned int humidity;

    AnimationBlock animationBlock;
    AnimatedSprite sprite;

  public:
    Block(unsigned int height = 0);
    Block(unsigned int height, unsigned int temperature);
    Block(unsigned int height, unsigned int temperature, unsigned int humidity);
    Block(unsigned int height, unsigned int temperature, unsigned int humidity, const TextureToolAnimation& biome);

    void animateBlock(sf::Vector3<float> positionStart, std::function<void(sf::Vector3<float>&)> animation, int framesDuration = 0);

    void update();

    unsigned int getHeight() const;
    unsigned int getTemperature() const;
    unsigned int getHumidity() const;

    sf::Vector3<float> getPosition() const;

    void setHeight(unsigned int height);
    void setTemperature(unsigned int temperature);
    void setHumidity(unsigned int humidity);
    void setPosition(const sf::Vector3<float>& position);
    void setPosition(int x, int y, int z);

    void setTexture(const TextureToolAnimation& texture);

    AnimatedSprite& getSprite();
};

#endif