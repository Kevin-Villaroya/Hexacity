#include "Position.h"

Position::Position(unsigned int x, unsigned int y) : x(x), y(y) {}
		
unsigned int Position::getX() const{
	return this->x;
}

unsigned int Position::getY() const{
	return this->y;
}