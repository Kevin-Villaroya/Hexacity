#ifndef __ANIMATION_BLOCK_H__
#define __ANIMATION_BLOCK_H__

#include "Animation.h"
#include <SFML/System/Vector3.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <functional>

class AnimationBlock : public Animation{
    private:
        std::function<void(sf::Vector3<float>&)> animation;
        sf::Vector3<float> currentPosition;
        sf::Vector3<float> endPosition;

        int framesDuration;
        int framesWaited;

    public:        
        AnimationBlock(sf::Vector3<float>& position);

        AnimationBlock(std::function<void(sf::Vector3<float>&)> animation, sf::Vector3<float>& positionStart, sf::Vector3<float> positionEnd, int framesDuration);

        void play() override;
        void update() override;

        const sf::Vector3<float>& getCurrentPosition() const;

        int getFramesDuration() const;
};

#endif