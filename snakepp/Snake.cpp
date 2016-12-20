#include <cmath>
#include <SDL.h>
#include "Snake.h"



Snake::Snake()
{
	direction = EAST;

	body.push_back({ 0,0 });
}


Snake::~Snake()
{
}

void Snake::Draw(SDL_Surface& surface)
{
	int move = 0;
	int ticks = SDL_GetTicks();
	int moveFreq = std::floor(1000 / speed);

	if (lastMoved == 0)
	{
		move = 1;
		lastMoved = ticks;
	}
	else if ((ticks - lastMoved) >= moveFreq)
	{
		move = (int)std::floor((ticks - lastMoved) / moveFreq);
		lastMoved = lastMoved + move*moveFreq;
	}

	
	if (move > 0)
	{
		Move(move);
		lastDirection = direction;
	}

	for (auto it = body.begin(); it != (body.end()--); ++it)
	{
		SDL_Rect rect = { it->x,it->y,10,10 };
		SDL_FillRect(&surface, &rect, 0x00ffffff);
	}
}

void Snake::Move(int m)
{
	for (; m > 0; m--)
	{
		tailLastPosition = body.front();
		for (auto it = body.begin(); it != (--body.end()); ++it)
		{
			auto nextPart = it;
			nextPart++;

			(*it) = (*nextPart);
		}
		
		switch (direction)
		{
		case NORTH:
			body.back().y -= 10;
			break;
		case SOUTH:
			body.back().y += 10;
			break;
		case EAST:
			body.back().x += 10;
			break;
		case WEST:
			body.back().x -= 10;
			break;
		}
	}
}

void Snake::AddPart()
{
	body.push_front(tailLastPosition);
}

void Snake::SetDirection(Direction dir)
{
	if ((dir == NORTH && lastDirection == SOUTH) ||
		(dir == SOUTH && lastDirection == NORTH) ||
		(dir == EAST && lastDirection == WEST) ||
		(dir == WEST && lastDirection == EAST))
		return;
	
	direction = dir;
}
