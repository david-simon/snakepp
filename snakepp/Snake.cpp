#include <cmath>
#include <algorithm>
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
	for (auto it = body.begin(); it != (body.end()--); ++it)
	{
		SDL_Rect rect = { it->x,it->y,10,10 };
		SDL_FillRect(&surface, &rect, 0x00ffffff);
	}
}

void Snake::Move()
{
	int m = 0;
	int ticks = SDL_GetTicks();
	int moveFreq = (int)std::floor(1000 / speed);

	if (lastMoved == 0)
	{
		m = 1;
		lastMoved = ticks;
	}
	else if ((ticks - lastMoved) >= moveFreq)
	{
		m = (int)std::floor((ticks - lastMoved) / moveFreq);
		lastMoved = lastMoved + m*moveFreq;
	}


	if (m > 0)
	{
		lastDirection = direction;

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
}

void Snake::AddPart()
{
	body.push_front(tailLastPosition);
}

void Snake::kill()
{
	while (body.size() > 1)
		body.remove(body.front());

	body.front().x = 0;
	body.front().y = 0;
	direction = EAST;
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

bool operator==(const SDL_Point& a, const SDL_Point& b)
{
	return a.x == b.x && a.y == b.y;
}
