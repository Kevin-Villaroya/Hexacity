#ifndef __HEXAGONAL_MAP_H__
#define __HEXAGONAL_MAP_H__

#include "block/Block.h"
#include <vector>
#include <SFML/Graphics/Sprite.hpp>

class Map{
	private:
		std::vector<std::vector<std::vector<Block>>> map;
		
		unsigned int width;
		unsigned int lenght;
	public:
		Map(unsigned int width, unsigned int lenght);

		Block& get(const sf::Vector2<float>& position);
		const Block& get(const sf::Vector2<float>& position) const;

		Block& get(uint x, uint y);
		const Block& get(uint x, uint y) const;

		unsigned int getWidth() const;
		unsigned int getLenght() const;

		unsigned int getDrawableWidth();
		unsigned int getDrawableLenght();

		unsigned int getSize() const;
};

#endif