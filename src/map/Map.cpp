#include "Map.h"
#include <iostream>

Map::Map(unsigned int width, unsigned int lenght) : width(width), lenght(lenght) {
	for(unsigned int x = 0; x < width; x++){

		std::vector<std::vector<Block>> line;


		for(unsigned int y = 0; y < lenght; y++){
			std::vector<Block> column;

			sf::Vector3<float> position(x, y, 0);
			Block currentCase;

			currentCase.setPosition(position);

			column.push_back(currentCase);

			line.push_back(column);
		}

		this->map.push_back(line);
	}
}

Block& Map::get(const sf::Vector2<float>& position){
	return this->get(position.x, position.y);
}

const Block& Map::get(const sf::Vector2<float>& position) const{
	return this->get(position.x, position.y);
}

Block& Map::get(uint x, uint y){
	return this->map[x][y][0];
}

const Block& Map::get(uint x, uint y) const{
	return this->map[x][y][0];
}

unsigned int Map::getWidth() const{
	return this->width;
}

unsigned int Map::getLenght() const{
	return this->lenght;
}

unsigned int Map::getDrawableWidth(){
	return this->width * this->get(sf::Vector2<float>(0, 0)).getSprite().getTexture()->getSize().x;
}

unsigned int Map::getDrawableLenght(){
	return this->lenght * (this->get(sf::Vector2<float>(0, 0)).getSprite().getTexture()->getSize().y / 2);
}

unsigned int Map::getSize() const{
	return this->width * this->lenght;
}