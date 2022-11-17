#include "AnimationBlock.h"
#include <iostream>

AnimationBlock::AnimationBlock(sf::Vector3<float>& position) : AnimationBlock([](sf::Vector3<float>&){}, position, sf::Vector3<float>(0, 0, 0), 0) {}

AnimationBlock::AnimationBlock(std::function<void(sf::Vector3<float>&)> animation, sf::Vector3<float>& positionStart, sf::Vector3<float> endPosition, int framesDuration) : Animation(), animation(animation), currentPosition(positionStart), endPosition(endPosition), framesDuration(framesDuration), framesWaited(0){}

void AnimationBlock::play(){
    this->running = true;
}

void AnimationBlock::update(){
    if(this->running && framesDuration == framesWaited){
        if(this->currentPosition.x == this->endPosition.x &&this->currentPosition.y == this->endPosition.y){
            this->running = false;
        }

        if(this->running){
            this->animation(this->currentPosition);
        }

        this->framesWaited = 0;
    }else{
        this->framesWaited++;
    }
}

const sf::Vector3<float>& AnimationBlock::getCurrentPosition() const{
    return this->currentPosition;
}

int AnimationBlock::getFramesDuration() const{
    return this->framesDuration;
}