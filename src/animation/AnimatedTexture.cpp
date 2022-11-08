#include "AnimatedTexture.h"
#include <iostream>

AnimatedTexture::AnimatedTexture(const TextureToolAnimation& textures, uint framesDuration) : 
    textures(textures), 
    currentTexture(0), 
    forward(true), 
    framesDuration(framesDuration), 
    framesWaited(0) 
{}

void AnimatedTexture::play(){
    this->running = true;
}

void AnimatedTexture::update(){
    if(framesWaited == framesDuration){
        framesWaited = 0;

        switch(this->forward){
            case true:
                this->currentTexture < this->textures.getSize() - 1? this->currentTexture++ : this->forward = false;
                break;
            default:
                this->currentTexture > 0 ? this->currentTexture-- : this->forward = true;
                break;
        }
    }else{
        framesWaited++;
    }
}

const TextureTool& AnimatedTexture::getTexture() const{
    return this->textures.getTexture(this->currentTexture);
}