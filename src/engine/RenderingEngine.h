#ifndef __RENDERING_ENGINE_H__
#define __RENDERING_ENGINE_H__

#include "../map/Map.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <list>
#include <memory>

class RenderingEngine{
	private:
		std::shared_ptr<Map> map;
		sf::View view;
		sf::RenderWindow window;

	public:
		RenderingEngine(std::shared_ptr<Map> map, unsigned int fps = 60, unsigned int widthWindow = 1920, unsigned int heightWindow = 1080);
		bool tick();

	private:
		void render();
		void drawMap();

		std::list<sf::Sprite*> getMapDrawables();

		void entranceAnimation();

		void setCaseSpritePosition(sf::Sprite& sprite, const sf::Vector3<float>& position, unsigned int height);
		void setEntitySpritePosition(sf::Sprite& blockSprite, Entity& entity, unsigned int height);

		sf::Vector3<float> getCenterDrawableMap();
		sf::Vector3<float> convertMapPositionToWindowPosition(const sf::Vector3<float>& position);
		sf::Vector3<float> transformEuclidianPositionToIsometric(const sf::Vector3<float>& position);
		bool checkEvents();
};

#endif