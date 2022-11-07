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

  public:
    AnimatedTexture(const TextureToolAnimation& textures);

    void play();
    void update();

    const TextureTool& getTexture() const;
};

#endif

