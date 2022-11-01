#ifndef __ENGINE_H__
#define __ENGINE_H__

#include "RenderingEngine.h"
#include "GameEngine.h"
#include "../map/Map.h"

class Engine{
	private:
		Map& map;
		GameEngine gameEngine;
		RenderingEngine renderingEngine;

		bool running;
	public:
		Engine(Map& map);

		void run();
};

#endif