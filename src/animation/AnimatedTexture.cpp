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
                this->currentTexture++;
                break;
            default:
                this->currentTexture--;
                break;
        }

        if(this->currentTexture == 0){
            this->forward = true;
        }else if(this->currentTexture == this->textures.getSize() - 1){
            this->forward = false;
        }
    }else{
        framesWaited++;
    }
}

const TextureTool& AnimatedTexture::getTexture() const{
    return this->textures.getTexture(this->currentTexture);
}