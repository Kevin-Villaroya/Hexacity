#ifndef __HEXAGONAL_MAP_H__
#define __HEXAGONAL_MAP_H__

#include "Position.h"
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

		Block& get(const Position& position);
		const Block& get(const Position& position) const;

		unsigned int getWidth() const;
		unsigned int getHeight() const;

		unsigned int getDrawableWidth();
		unsigned int getDrawableHeight();

		unsigned int getNumberOfCases() const;
};

#endif