#include "AnimationBlock.h"
#include <iostream>

AnimationBlock::AnimationBlock(Position& position) : AnimationBlock([](Position&){}, position, Position(0, 0), 0) {}

AnimationBlock::AnimationBlock(std::function<void(Position&)> animation, Position& positionStart, Position endPosition, int framesDuration) : Animation(), animation(animation), currentPosition(positionStart), endPosition(endPosition), framesDuration(framesDuration), framesWaited(0){}

void AnimationBlock::play(){
    this->running = true;
}

void AnimationBlock::update(){
    if(this->running && framesDuration == framesWaited){
        if(this->currentPosition.getX() == this->endPosition.getX() &&this->currentPosition.getY() == this->endPosition.getY()){
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

const Position& AnimationBlock::getCurrentPosition() const{
    return this->currentPosition;
}

int AnimationBlock::getFramesDuration() const{
    return this->framesDuration;
}