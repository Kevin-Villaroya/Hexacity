#ifndef __ENGINE_H__
#define __ENGINE_H__

#include "RenderingEngine.h"
#include "GameEngine.h"
#include "../map/Map.h"
#include <memory>

class Engine{
	private:
		std::shared_ptr<Map> map;
		GameEngine gameEngine;
		RenderingEngine renderingEngine;

		bool running;
	public:
		Engine(std::shared_ptr<Map> map);

		void run();
};

#endif