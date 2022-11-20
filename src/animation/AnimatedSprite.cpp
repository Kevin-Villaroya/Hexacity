#include "AnimatedSprite.h"
#include <iostream>

AnimatedSprite::AnimatedSprite() : 
AnimatedSprite(TextureToolAnimation::basic)
{}

AnimatedSprite::AnimatedSprite(const TextureToolAnimation& textures, uint framesDuration) : 
textures(textures),
framesDuration(framesDuration),
framesWaited(0),
currentFrame(0)
{
  this->play();
  this->setTexture(this->textures.get().getTexture(currentFrame));
}

void AnimatedSprite::play(){
  this->running = true;

  this->framesWaited = 0;
  this->currentFrame = 0;
}

void AnimatedSprite::update(){
  if(framesWaited >= framesDuration){
    this->nextTexture();
    //this->setTexture(this->textures.get().getTexture(this->currentFrame));

    framesWaited = 0;
  }else{
    framesWaited++;
  }
}

void AnimatedSprite::nextTexture(){
  if(this->currentFrame < this->textures.get().getSize() - 1){
    this->currentFrame++;
  }else{
    this->currentFrame = 0;
  }
}

void AnimatedSprite::setTextures(const TextureToolAnimation& textures){
  this->textures = textures;

  this->play();

  this->setTexture(this->textures.get().getTexture(this->currentFrame));
}