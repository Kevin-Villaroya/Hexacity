#include "map/Map.h"
#include "engine/Engine.h"
#include <iostream>

int main(){
	Map map(10, 10);
	Engine game(map);

	game.run();

	return 0;
}