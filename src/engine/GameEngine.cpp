#include "GameEngine.h"
#include <iostream>

GameEngine::GameEngine(Map& map, int ticksBeforeEachUpdate) : map(map), ticksBeforeEachUpdate(ticksBeforeEachUpdate), ticksBeforeLastUpdate(0) {
	this->initMap();
}

void GameEngine::initMap(){
	uint width = this->map.getWidth();
	uint height = this->map.getLenght();

	for(unsigned int i = 0; i < width; i++){
		for(unsigned int j = 0; j < height; j++){
			if(i == j || i == j-1 || i == j+1 || j == i-1 || j == i+1){
				this->map.get(i, j).setTexture(TextureToolAnimation::water);
			}

			if(i == 0){
				this->map.setHeightBlock(i, j, 1);
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
	this->map.update();

	return true;
}