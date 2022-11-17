#include "SpriteTool.h"

TextureTool SpriteTool::none = TextureTool("assets/none.png");

SpriteTool::SpriteTool() : SpriteTool(SpriteTool::none){}

SpriteTool::SpriteTool(const TextureTool& texture) :  sf::Sprite(), texture(texture){
  this->setTexture(this->texture);
}