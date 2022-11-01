#ifndef __RENDERING_ENGINE_H__
#define __RENDERING_ENGINE_H__

#include "../map/Map.h"
#include <SFML/Graphics.hpp>
#include <list>

class RenderingEngine{
	private:
		Map& map;
		sf::View view;
		sf::RenderWindow window;

	public:
		RenderingEngine(Map& map, unsigned int fps = 60, unsigned int widthWindow = 1920, unsigned int heightWindow = 1080);
		bool tick();

	private:
		void render();
		void drawMap();
		std::list<std::reference_wrapper<SpriteTool>> getMapDrawables();

		void entranceAnimation();

		void setCaseSpritePosition(SpriteTool& sprite, const Position& position, unsigned int height);

		Position getCenterDrawableMap();
		Position convertMapPositionToWindowPosition(const Position& position);
		Position transformEuclidianPositionToIsometric(const Position& position);
		bool checkEvents();
};

#endif