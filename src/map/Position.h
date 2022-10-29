#ifndef __POSITION_H__
#define __POSITION_H__

class Position{
	
	private:
		unsigned int x;
		unsigned int y;
	public:
		Position(unsigned int x, unsigned int y);
		
		unsigned int getX() const;
		unsigned int getY() const;
};

#endif