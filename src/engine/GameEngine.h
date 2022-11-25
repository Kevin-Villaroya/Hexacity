#ifndef __GAME_ENGINE_H__
#define __GAME_ENGINE_H__

#include "../map/Map.h"
#include <memory>

class GameEngine{
	private:
		private:
		std::shared_ptr<Map> map;

		unsigned int ticksBeforeEachUpdate;
		unsigned int ticksBeforeLastUpdate;

	public:
		GameEngine(std::shared_ptr<Map>& map, int ticksBeforeEachUpdate = 0);
		bool tick();

	private:
		bool update();
		void initMap();
};

#endif