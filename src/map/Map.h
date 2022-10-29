#ifndef __HEXAGONAL_MAP_H__
#define __HEXAGONAL_MAP_H__

#include "Position.h"
#include "case/Case.h"
#include <vector>

class Map{
	private:
		std::vector<std::vector<Case> > map;
		unsigned int width;
		unsigned int height;
	public:
		Map(unsigned int width, unsigned int height);

		Case& get(const Position& position);
		const Case& get(const Position& position) const;
};

#endif