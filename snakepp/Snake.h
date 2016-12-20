#pragma once
#include <list>
#include <SDL.h>

class Snake
{
public:
	enum Direction
	{
		NORTH,
		WEST,
		SOUTH,
		EAST
	};

private:
	Direction direction, lastDirection;

	std::list<SDL_Point> body;
	int lastMoved;
	SDL_Point tailLastPosition;

public:
	int speed = 5; // unit/s

	Snake();
	~Snake();

	void Draw(SDL_Surface& surface);
	void Move(int m);
	void AddPart();
	void SetDirection(Direction dir);
	inline Direction GetDirection() { return lastDirection; };
};

