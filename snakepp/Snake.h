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
	int speed = 10; // unit/s

	Snake();
	~Snake();

	void Draw(SDL_Surface& surface);
	
	void Move();
	void AddPart();
	void kill();
	
	void SetDirection(Direction dir);
	inline const Direction& GetDirection() { return lastDirection; };
	inline const std::list<SDL_Point>& GetBody() { return body; };

	bool CheckCollision();
	bool CheckPickup();
};

