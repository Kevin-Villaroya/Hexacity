#ifndef __ANIMATED_TEXTURE_H__
#define __ANIMATED_TEXTURE_H__

#include "./Animation.h"
#include "../../tool/TextureTool.h"
#include "../tool/TextureToolAnimation.h"

class AnimatedTexture : public Animation{
  private:
    const TextureToolAnimation& textures;

    uint currentTexture;
    bool forward;

    uint framesDuration;
    uint framesWaited;

  public:
    AnimatedTexture(const TextureToolAnimation& textures, uint framesDuration = 0);

    void play();
    void update();

    const TextureTool& getTexture() const;
};

#endif

