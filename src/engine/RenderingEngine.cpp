#include "RenderingEngine.h"
#include <iostream>

RenderingEngine::RenderingEngine(Map& map, unsigned int fps) : map(map){}

void RenderingEngine::tick(){
	this->render();
}

void RenderingEngine::render(){
	std::cout << "RenderingEngine" << std::endl;
}