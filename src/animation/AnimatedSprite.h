#ifndef __ANIMATED_SPRITE_H__
#define __ANIMATED_SPRITE_H__

#include "./Animation.h"
#include "../tool/TextureToolAnimation.h"
#include <SFML/Graphics/Sprite.hpp>

class AnimatedSprite : public sf::Sprite, public Animation{
  private:
    std::reference_wrapper<const TextureToolAnimation> textures;
    
    uint framesDuration;
    uint framesWaited;
    uint currentFrame;

  public:
    AnimatedSprite();
    AnimatedSprite(const TextureToolAnimation& textures, uint framesDuration = 0);

    void play() override;
    void update() override;
    void setTextures(const TextureToolAnimation& textures);

  private:
    void nextTexture();
};

#endif