#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "../biome/Biome.h"
#include "../../animation/AnimatedSprite.h"
#include "../../animation/AnimationBlock.h"
#include "../entity/Entity.h"
#include "../entity/TypeEntity.h"

#include <SFML/System/Vector3.hpp>
#include <optional>
#include <memory>

class Block{
  private:
    sf::Vector3<float> position;

    unsigned int height;
    unsigned int temperature;
    unsigned int humidity;

    AnimationBlock animationBlock;
    AnimatedSprite sprite;

    std::optional<std::unique_ptr<Entity>> entity;

  public:
    Block();
    Block(unsigned int height);
    Block(unsigned int height, unsigned int temperature);
    Block(unsigned int height, unsigned int temperature, unsigned int humidity);
    Block(unsigned int height, unsigned int temperature, unsigned int humidity, const TextureToolAnimation& biome);

    void copyTo(Block& block);

    void animateBlock(sf::Vector3<float> positionStart, std::function<void(sf::Vector3<float>&)> animation, int framesDuration = 0);

    void update();

    void addEntity(TypeEntity type);
    bool hasEntity() const;

    const Entity& getEntity() const;
    Entity& getEntity();

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