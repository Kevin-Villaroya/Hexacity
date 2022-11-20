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

Block& Map::get(uint x, uint y){
	return this->map[x][y][this->map[x][y].size() - 1];
}

const Block& Map::get(uint x, uint y) const{
	return this->map[x][y][this->map[x][y].size() - 1];
}

Block& Map::get(uint x, uint y, uint z){
	return this->map[x][y][z];
}

const Block& Map::get(uint x, uint y, uint z) const{
	return this->map[x][y][z];
}

std::vector<Block>& Map::getColumn(uint x, uint y){
	return this->map[x][y];
}

void Map::setHeightBlock(const Block& block, uint height){
	this->setHeightBlock(block.getPosition().x, block.getPosition().y, height);
}

void Map::setHeightBlock(uint x, uint y, uint height){
	Block topBlock = this->get(x, y);
	topBlock.setHeight(height);

	this->map[x][y].clear();

	Block block;

	while(this->map[x][y].size() < height){
		block.setHeight(0); 
		block.setPosition(topBlock.getPosition());
		block.setTexture(TextureToolAnimation::basic);

		this->map[x][y].push_back(block);
	}

	this->map[x][y].push_back(topBlock);
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