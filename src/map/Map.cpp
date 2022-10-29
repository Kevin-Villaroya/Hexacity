#include "Map.h"

Map::Map(unsigned int width, unsigned int height) : width(width), height(height) {
	for(unsigned int i = 0; i < width; i++){
		std::vector<Case> line;

		for(unsigned int j = 0; j < height; j++){
			Case currentCase;
			line.push_back(currentCase);
		}

		this->map.push_back(line);
	}
}

Case& Map::get(const Position& position){
	return this->map[position.getX()][position.getY()];
}

const Case& Map::get(const Position& position) const{
	return this->map[position.getX()][position.getY()];
}