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

		void setCaseSpritePosition(SpriteTool& sprite, const sf::Vector3<float>& position, unsigned int height);

		sf::Vector3<float> getCenterDrawableMap();
		sf::Vector3<float> convertMapPositionToWindowPosition(const sf::Vector3<float>& position);
		sf::Vector3<float> transformEuclidianPositionToIsometric(const sf::Vector3<float>& position);
		bool checkEvents();
};

#endif