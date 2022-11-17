#ifndef __POSITION_H__
#define __POSITION_H__

class Position{
	
	private:
		int x;
		int y;
	public:
		Position();
		Position(int x, int y);
		
		int getX() const;
		int getY() const;

		void setX(int x);
		void setY(int y);

		Position& operator =(const Position& position);
};

#endif