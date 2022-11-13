#include "GameEngine.h"
#include <iostream>

GameEngine::GameEngine(Map& map, int ticksBeforeEachUpdate) : map(map), ticksBeforeEachUpdate(ticksBeforeEachUpdate), ticksBeforeLastUpdate(0) {
	this->initMap();
}

void GameEngine::initMap(){
	uint width = this->map.getWidth();
	uint height = this->map.getHeight();

	for(unsigned int i = 0; i < width; i++){
		for(unsigned int j = 0; j < height; j++){
			if(i == j || i == j-1 || i == j+1 || j == i-1 || j == i+1){
				this->map.get(i, j).setTexture(TextureToolAnimation::water);
			}
		}
	}
}

bool GameEngine::tick(){
	bool continueRunning = true;

	if(ticksBeforeLastUpdate == ticksBeforeEachUpdate){		
		continueRunning = this->update();
		this->ticksBeforeLastUpdate = 0;
	}else{
		this->ticksBeforeLastUpdate++;
	}

	return continueRunning;
}

bool GameEngine::update(){
	for(unsigned int i = 0; i < this->map.getWidth(); i++){
		for(unsigned int j = 0; j < this->map.getHeight(); j++){
			this->map.get(sf::Vector2<float>(i, j)).update();
		}
	}

	return true;
}