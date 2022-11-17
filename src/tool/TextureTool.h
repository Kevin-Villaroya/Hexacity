#ifndef __TEXTURE_TOOL_H__
#define __TEXTURE_TOOL_H__

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Network/Packet.hpp>
#include <string>

class TextureTool : public sf::Texture{

public:
  TextureTool();
  TextureTool(const std::string& locationAsset);
};

#endif
