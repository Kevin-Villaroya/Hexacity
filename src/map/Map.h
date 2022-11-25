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

		void update();

		void addEntity(sf::Vector2f position, TypeEntity typeEntity);
		void removeEntity(sf::Vector2f position, sf::Vector2f size);

		Block& get(const sf::Vector2<float>& position);
		const Block& get(const sf::Vector2<float>& position) const;

		Block& get(uint x, uint y);
		const Block& get(uint x, uint y) const;

		Block& get(uint x, uint y, uint z);
		const Block& get(uint x, uint y, uint z) const;

		std::vector<Block>& getColumn(uint x, uint y);

		void setHeightBlock(const Block& block, uint height);
		void setHeightBlock(uint x, uint y, uint height);

		unsigned int getWidth() const;
		unsigned int getLenght() const;

		unsigned int getDrawableWidth();
		unsigned int getDrawableLenght();

		unsigned int getSize() const;
};

#endif