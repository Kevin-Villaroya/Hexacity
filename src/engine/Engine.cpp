#include "Engine.h"

Engine::Engine(Map& map) : map(map), renderingEngine(map), gameEngine(map, 50), running(false){}

void Engine::run(){
	this->running = true;

	while(this->running){
		this->renderingEngine.tick();
		this->running = this->gameEngine.tick();
	}
}