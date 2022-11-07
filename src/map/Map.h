#ifndef __HEXAGONAL_MAP_H__
#define __HEXAGONAL_MAP_H__

#include "block/Block.h"
#include <vector>
#include <SFML/Graphics/Sprite.hpp>

class Map{
	private:
		std::vector<std::vector<Block>> map;
		
		unsigned int width;
		unsigned int height;
	public:
		Map(unsigned int width, unsigned int height);

		Block& get(const sf::Vector2<float>& position);
		const Block& get(const sf::Vector2<float>& position) const;

		Block& get(uint x, uint y);
		const Block& get(uint x, uint y) const;

		unsigned int getWidth() const;
		unsigned int getHeight() const;

		unsigned int getDrawableWidth();
		unsigned int getDrawableHeight();

		unsigned int getNumberOfCases() const;
};

#endif