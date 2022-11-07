#include "AnimatedTexture.h"
#include <iostream>

AnimatedTexture::AnimatedTexture(const TextureToolAnimation& textures) : textures(textures), currentTexture(0), forward(true) {}

void AnimatedTexture::play(){
    this->running = true;
}

void AnimatedTexture::update(){
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
}

const TextureTool& AnimatedTexture::getTexture() const{
    return this->textures.getTexture(this->currentTexture);
}