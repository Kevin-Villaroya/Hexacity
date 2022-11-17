#include "Engine.h"
#include <iostream>

Engine::Engine(Map& map) : map(map), gameEngine(map, 1), renderingEngine(map), running(false){}

void Engine::run(){
	this->running = true;

	while(this->running){
		this->running &= this->gameEngine.tick();
		this->running &= this->renderingEngine.tick();
	}
}