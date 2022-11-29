#include "map/Map.h"
#include "engine/Engine.h"
#include "map/generator/FactoryMap.h"
#include <iostream>
#include <memory>

int main(){
	std::shared_ptr<Map> map = FactoryMap::generateMap(30, 30);
	Engine game(map);

	game.run();

	return 0;
}