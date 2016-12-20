#pragma once
#include <SDL.h>

class Pickup
{
public:
	SDL_Point position;

	Pickup(int x, int y);
	void Draw(SDL_Surface& surface);
};

