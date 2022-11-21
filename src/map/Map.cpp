#include "Map.h"
#include <iostream>

Map::Map(unsigned int width, unsigned int lenght) : width(width), lenght(lenght) {
	for(unsigned int x = 0; x < width; x++){
		auto& line = this->map.emplace_back();

		for(unsigned int y = 0; y < lenght; y++){
			auto& column = line.emplace_back();

			sf::Vector3<float> position(x, y, 0);			
			Block& block = column.emplace_back();

			block.setPosition(position);
		}
	}
}

void Map::update(){
	for(unsigned int x = 0; x < this->getWidth(); x++){
		for(unsigned int y = 0; y < this->getLenght(); y++){
			for(unsigned int z = 0; z < this->getColumn(x, y).size(); z++){
				this->get(x, y, z).update();
			}
		}
	}
}

Block& Map::get(const sf::Vector2<float>& position){
	return this->get(position.x, position.y);
}

const Block& Map::get(const sf::Vector2<float>& position) const{
	return this->get(position.x, position.y);
}

Block& Map::get(unsigned int x, unsigned int y){
	return this->map[x][y][this->map[x][y].size() - 1];
}

const Block& Map::get(unsigned int x, unsigned int y) const{
	return this->map[x][y][this->map[x][y].size() - 1];
}

Block& Map::get(unsigned int x, unsigned int y, unsigned int z){
	return this->map[x][y][z];
}

const Block& Map::get(unsigned int x, unsigned int y, unsigned int z) const{
	return this->map[x][y][z];
}

std::vector<Block>& Map::getColumn(unsigned int x, unsigned int y){
	return this->map[x][y];
}

void Map::setHeightBlock(const Block& block, unsigned int height){
	this->setHeightBlock(block.getPosition().x, block.getPosition().y, height);
}

void Map::setHeightBlock(unsigned int x, unsigned int y, unsigned int height){
	Block topBlock;
	this->get(x, y).copyTo(topBlock);

	this->map[x][y].clear();

	for(unsigned int z = 0; z <= height; z++){
		Block& block = this->map[x][y].emplace_back();

		block.setHeight(z);
		block.setPosition(x, y, z);
		block.setTexture(TextureToolAnimation::basic);
	}

	topBlock.copyTo(this->map[x][y][height]);
	this->map[x][y][height].setHeight(height);
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