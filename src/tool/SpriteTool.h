#ifndef __SPRITE_TOOL_H__
#define __SPRITE_TOOL_H__

#include "TextureTool.h"
#include <SFML/Graphics/Sprite.hpp>
#include <string>

class SpriteTool : public sf::Sprite{
private:
  static TextureTool none;

  const TextureTool& texture;
  
public:
  SpriteTool();
  SpriteTool(const TextureTool& texture);
};

#endif
