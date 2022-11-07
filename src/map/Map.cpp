#include "Map.h"
#include <iostream>

Map::Map(unsigned int width, unsigned int height) : width(width), height(height) {
	for(unsigned int i = 0; i < width; i++){

		std::vector<Block> line;

		for(unsigned int j = 0; j < height; j++){
			sf::Vector2<float> position(i, j);
			Block currentCase;

			currentCase.setPosition(position);

			line.push_back(currentCase);
		}

		this->map.push_back(line);
	}
}

Block& Map::get(const sf::Vector2<float>& position){
	return this->map[position.x][position.y];
}

const Block& Map::get(const sf::Vector2<float>& position) const{
	return this->map[position.x][position.y];
}

Block& Map::get(uint x, uint y){
	return this->map[x][y];
}

const Block& Map::get(uint x, uint y) const{
	return this->map[x][y];
}

unsigned int Map::getWidth() const{
	return this->width;
}

unsigned int Map::getHeight() const{
	return this->height;
}

unsigned int Map::getDrawableWidth(){
	return this->width * this->get(sf::Vector2<float>(0, 0)).getSprite().getTexture()->getSize().x;
}

unsigned int Map::getDrawableHeight(){
	return this->height * (this->get(sf::Vector2<float>(0, 0)).getSprite().getTexture()->getSize().y / 2);
}

unsigned int Map::getNumberOfCases() const{
	return this->width * this->height;
}