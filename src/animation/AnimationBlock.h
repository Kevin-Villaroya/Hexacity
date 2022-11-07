#ifndef __ANIMATION_BLOCK_H__
#define __ANIMATION_BLOCK_H__

#include "Animation.h"
#include <SFML/Graphics/Sprite.hpp>
#include <functional>

class AnimationBlock : public Animation{
    private:
        std::function<void(sf::Vector2<float>&)> animation;
        sf::Vector2<float> currentPosition;
        sf::Vector2<float> endPosition;

        int framesDuration;
        int framesWaited;

    public:        
        AnimationBlock(sf::Vector2<float>& position);

        AnimationBlock(std::function<void(sf::Vector2<float>&)> animation, sf::Vector2<float>& positionStart, sf::Vector2<float> positionEnd, int framesDuration);

        void play() override;
        void update() override;

        const sf::Vector2<float>& getCurrentPosition() const;

        int getFramesDuration() const;
};

#endif