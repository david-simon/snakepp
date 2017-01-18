#pragma once
#include <vector>
#include <SDL.h>
#include "Game.h"

class Renderer
{
	SDL_Window* win;
	SDL_Renderer* renderer;
	SDL_Surface* surface;
	bool quit;

public:
	Renderer(int width, int height, int flags);
	~Renderer();

	void Render();
	void Stop();

	SDL_Surface& GetSurface();
};

