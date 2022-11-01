#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "../biome/Biome.h"
#include "../../tool/SpriteTool.h"
#include "../../tool/TextureTool.h"
#include "../../animation/AnimationBlock.h"
#include "../Position.h"

class Block{
  public:
    static const TextureTool block;

  private:
    Position position;

    unsigned int height;
    unsigned int temperature;
    unsigned int humidity;

    SpriteTool sprite;
    AnimationBlock animationBlock;

  public:
    Block(unsigned int height = 0);
    Block(unsigned int height, unsigned int temperature);
    Block(unsigned int height, unsigned int temperature, unsigned int humidity);

    void animate(Position positionStart, std::function<void(Position&)> animation, int framesDuration = 0);

    void update();

    unsigned int getHeight() const;
    unsigned int getTemperature() const;
    unsigned int getHumidity() const;
    Position getPosition();

    void setHeight(unsigned int height);
    void setTemperature(unsigned int temperature);
    void setHumidity(unsigned int humidity);
    void setPosition(const Position& position);
    void setPosition(int x, int y);

    SpriteTool& getSprite();
};

#endif