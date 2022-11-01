#include "map/Map.h"
#include "engine/Engine.h"
#include <iostream>

int main(){
	Map map(30, 30);
	Engine game(map);

	game.run();

	return 0;
}