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
			Block& currentCase = this->map.get(i, j);

			if(i == 1 || j == 1 || i == width - 2 || j == height - 2){
				currentCase.setHeight(1);
			}

			if(i == 0 || j == 0 || i == width - 1 || j == height - 1){
				currentCase.setHeight(2);
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