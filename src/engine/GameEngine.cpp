#include "GameEngine.h"
#include <iostream>

GameEngine::GameEngine(Map& map, int ticksBeforeEachUpdate) : map(map), ticksBeforeEachUpdate(ticksBeforeEachUpdate), ticksBeforeLastUpdate(0) {
	this->initMap();
}

void GameEngine::initMap(){
	for(unsigned int i = 0; i < this->map.getWidth(); i++){
		for(unsigned int j = 0; j < this->map.getHeight(); j++){
			this->map.get(Position(i, j)).getSprite().setPosition(i, j);
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
			this->map.get(Position(i, j)).update();
		}
	}

	return true;
}