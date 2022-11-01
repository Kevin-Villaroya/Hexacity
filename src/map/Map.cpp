#include "Map.h"
#include <iostream>

Map::Map(unsigned int width, unsigned int height) : width(width), height(height) {
	for(unsigned int i = 0; i < width; i++){

		std::vector<Block> line;

		for(unsigned int j = 0; j < height; j++){
			Position position(i, j);
			Block currentCase;

			currentCase.setPosition(position);

			if(i == 1 || j == 1 || i == width - 2 || j == height - 2){
				currentCase.setHeight(1);
			}
			if(i == 0 || j == 0 || i == width - 1 || j == height - 1){
				currentCase.setHeight(2);
			}

			line.push_back(currentCase);
		}

		this->map.push_back(line);
	}
}

Block& Map::get(const Position& position){
	return this->map[position.getX()][position.getY()];
}

const Block& Map::get(const Position& position) const{
	return this->map[position.getX()][position.getY()];
}

unsigned int Map::getWidth() const{
	return this->width;
}

unsigned int Map::getHeight() const{
	return this->height;
}

unsigned int Map::getDrawableWidth(){
	return this->width * this->get(Position(0, 0)).getSprite().getTexture()->getSize().x;
}

unsigned int Map::getDrawableHeight(){
	return this->height * (this->get(Position(0, 0)).getSprite().getTexture()->getSize().y / 2);
}

unsigned int Map::getNumberOfCases() const{
	return this->width * this->height;
}