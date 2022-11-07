#ifndef __ANIMATED_TEXTURE_H__
#define __ANIMATED_TEXTURE_H__

#include "./Animation.h"
#include "../../tool/TextureTool.h"

class AnimatedTexture : public Animation{
  public:
    static const AnimatedTexture block;
    static const AnimatedTexture plain;
    static const AnimatedTexture water;

  private:
    std::vector<TextureTool> textures;

    AnimatedTexture(std::string path);

  public:
    virtual void play();
    virtual void update();

    const sf::Texture& getTexture() const;
};

#endif