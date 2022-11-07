#include "Block.h"
#include <iostream>

const TextureTool Block::block = TextureTool("./assets/block.png");

Block::Block(unsigned int height) : Block(height, 0) {}

Block::Block(unsigned int height, unsigned int temperature) : Block(height, temperature, 0) {}

Block::Block(unsigned int height, unsigned int temperature, unsigned int humidity) : height(height), temperature(temperature), humidity(humidity), sprite(Block::block), animationBlock(this->position) {}

void Block::animate(sf::Vector2<float> positionStart, std::function<void(sf::Vector2<float>&)> animation, int framesDuration){
  this->animationBlock = AnimationBlock(animation, positionStart, this->position, framesDuration);

  this->animationBlock.play();
}

void Block::update(){
  this->animationBlock.update();
}

unsigned int Block::getHeight() const{
  return this->height;
}

unsigned int Block::getTemperature() const{
  return this->temperature;
}

unsigned int Block::getHumidity() const{
  return this->humidity;
}

sf::Vector2<float> Block::getPosition(){
  if(this->animationBlock.isRunning()){
    return this->animationBlock.getCurrentPosition();
  }

  return this->position;
}

void Block::setHeight(unsigned int height){
  this->height = height;
}

void Block::setTemperature(unsigned int temperature){
  this->temperature = temperature;
}

void Block::setHumidity(unsigned int humidity){
  this->humidity = humidity;
}

void Block::setPosition(const sf::Vector2<float>& position){
  this->position = position;
}

void Block::setPosition(int x, int y){
  this->position = sf::Vector2<float>(x, y);
}

SpriteTool& Block::getSprite(){  
  return this->sprite;
}