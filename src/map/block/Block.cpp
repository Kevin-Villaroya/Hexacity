#include "Block.h"
#include "../../tool/TextureToolAnimation.h"
#include "../entity/FactoryEntity.h"
#include <iostream>

Block::Block() : Block(0){}

Block::Block(unsigned int height) : Block(height, 0) {}

Block::Block(unsigned int height, unsigned int temperature) :
  Block(height, temperature, 0)
{}

Block::Block(unsigned int height, unsigned int temperature, unsigned int humidity) :
Block(height, temperature, humidity, TextureToolAnimation::plain)
{}

Block::Block(unsigned int height, unsigned int temperature, unsigned int humidity, const TextureToolAnimation& biome) :
  height(height),
  temperature(temperature),
  humidity(humidity),
  animationBlock(this->position),
  sprite(biome)
{}

void Block::copyTo(Block& block){
  block.height = this->height;
  block.temperature = this->temperature;
  block.humidity = this->humidity;
  block.animationBlock = this->animationBlock;
  block.sprite = this->sprite;

  if(this->hasEntity()){
    block.entity = std::move(FactoryEntity::create(this->getEntity().getType()));
  }
}

void Block::animateBlock(sf::Vector3<float> positionStart, std::function<void(sf::Vector3<float>&)> animation, int framesDuration){
  this->animationBlock = AnimationBlock(animation, positionStart, this->position, framesDuration);

  this->animationBlock.play();
}

void Block::update(){
  this->animationBlock.update();
  this->sprite.update();
}

void Block::addEntity(TypeEntity type){
  this->entity = std::move(FactoryEntity::create(type));
}

bool Block::hasEntity() const{
  return this->entity.has_value();
}

const Entity& Block::getEntity() const{
  return *this->entity.value().get();
}

Entity& Block::getEntity(){
  return *this->entity.value().get();
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

sf::Vector3<float> Block::getPosition() const{
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

void Block::setPosition(const sf::Vector3<float>& position){
  this->position = position;
}

void Block::setPosition(int x, int y, int z){
  this->position = sf::Vector3<float>(x, y, z);
}

void Block::setTexture(const TextureToolAnimation& texture){
  this->sprite.setTextures(texture);
}

AnimatedSprite& Block::getSprite(){ 
  return this->sprite;
}