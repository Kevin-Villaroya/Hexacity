#ifndef __ENGINE_H__
#define __ENGINE_H__

#include "RenderingEngine.h"
#include "GameEngine.h"
#include "../map/Map.h"

class Engine{
	private:
		Map& map;
		RenderingEngine renderingEngine;
		GameEngine gameEngine;

		bool running;
	public:
		Engine(Map& map);

		void run();
};

#endif