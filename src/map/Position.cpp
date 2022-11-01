#include "Position.h"
#include <iostream>

Position::Position() : Position(0, 0) {}

Position::Position(int x, int y) : x(x), y(y) {}

int Position::getX() const{
	return this->x;
}

int Position::getY() const{
	return this->y;
}

void Position::setX(int x){
	this->x = x;
}

void Position::setY(int y){
	this->y = y;
}

Position& Position::operator =(const Position& position){
	this->x = position.getX();
	this->y = position.getY();

	return *this;
}