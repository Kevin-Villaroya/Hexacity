#ifndef __GAME_ENGINE_H__
#define __GAME_ENGINE_H__

#include "../map/Map.h"

class GameEngine{
	private:
		private:
		Map& map;

		unsigned int ticksBeforeEachUpdate;
		unsigned int ticksBeforeLastUpdate;

	public:
		GameEngine(Map& map, int ticksBeforeEachUpdate = 0);
		bool tick();

	private:
		bool update();
		void initMap();
};

#endif