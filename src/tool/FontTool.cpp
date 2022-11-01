#include "FontTool.h"

FontTool::FontTool() : sf::Font(){}

FontTool::FontTool(const std::string& locationFolder) : sf::Font(){
  this->loadFromFile(locationFolder);
}
