#ifndef __ANIMATION_BLOCK_H__
#define __ANIMATION_BLOCK_H__

#include "Animation.h"
#include "../map/Position.h"
#include <SFML/Graphics/Sprite.hpp>

class AnimationBlock : public Animation{
    private:
        std::function<void(Position&)> animation;
        Position currentPosition;
        Position endPosition;

        int framesDuration;
        int framesWaited;

    public:        
        AnimationBlock(Position& position);

        AnimationBlock(std::function<void(Position&)> animation, Position& positionStart, Position endPosition, int framesDuration);

        void play() override;
        void update() override;

        const Position& getCurrentPosition() const;

        int getFramesDuration() const;
};

#endif