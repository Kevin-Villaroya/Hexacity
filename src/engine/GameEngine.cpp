#include "GameEngine.h"
#include <iostream>

GameEngine::GameEngine(std::shared_ptr<Map>& map, int ticksBeforeEachUpdate) : map(map), ticksBeforeEachUpdate(ticksBeforeEachUpdate), ticksBeforeLastUpdate(0) {}

void GameEngine::initMap(){
	uint width = this->map.get()->getWidth();
	uint height = this->map.get()->getLenght();

	for(unsigned int i = 0; i < width; i++){
		for(unsigned int j = 0; j < height; j++){
			if(i == j || i == j-1 || i == j+1 || j == i-1 || j == i+1){
				this->map.get()->get(i, j).setTexture(TextureToolAnimation::water);
			}else if(i % 2 == 0){
				//this->map.get()->addEntity(sf::Vector2f(i, j), TypeEntity::forest);
			}else{
				//this->map.get()->addEntity(sf::Vector2f(i, j), TypeEntity::house);
			}

			if(i == 2 && j == 6){
				this->map.get()->addEntity(sf::Vector2f(i, j), TypeEntity::mountain);
			}

			if(i == 0){
				//this->map.get()->setHeightBlock(i, j, 1);
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
	this->map.get()->update();

	return true;
}