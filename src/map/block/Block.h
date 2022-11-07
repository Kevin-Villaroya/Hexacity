#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "../biome/Biome.h"
#include "../../tool/SpriteTool.h"
#include "../../animation/AnimatedTexture.h"
#include "../../animation/AnimationBlock.h"

class Block{
  private:
    sf::Vector2<float> position;

    unsigned int height;
    unsigned int temperature;
    unsigned int humidity;

    AnimationBlock animationBlock;
    AnimatedTexture animationTexture;

    SpriteTool sprite;

  public:
    Block(unsigned int height = 0);
    Block(unsigned int height, unsigned int temperature);
    Block(unsigned int height, unsigned int temperature, unsigned int humidity);

    void animateBlock(sf::Vector2<float> positionStart, std::function<void(sf::Vector2<float>&)> animation, int framesDuration = 0);

    void update();

    unsigned int getHeight() const;
    unsigned int getTemperature() const;
    unsigned int getHumidity() const;
    sf::Vector2<float> getPosition();

    void setHeight(unsigned int height);
    void setTemperature(unsigned int temperature);
    void setHumidity(unsigned int humidity);
    void setPosition(const sf::Vector2<float>& position);
    void setPosition(int x, int y);

    SpriteTool& getSprite();
};

#endif