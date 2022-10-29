#ifndef __RENDERING_ENGINE_H__
#define __RENDERING_ENGINE_H__

#include "../map/Map.h"

class RenderingEngine{
	private:
		Map& map;

	public:
		RenderingEngine(Map& map, unsigned int fps = __UINT16_MAX__);
		void tick();

	private:
		void render();
};

#endif