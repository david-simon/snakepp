#pragma once
#include <SDL.h>

class Pickup
{
public:
	SDL_Point position;

	Pickup();
	void Draw(SDL_Surface& surface);
	void Generate();
};

