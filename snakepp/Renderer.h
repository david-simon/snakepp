#pragma once
#include <SDL.h>

class Renderer
{
	SDL_Window* win;
	SDL_Renderer* renderer;

public:
	Renderer(int width, int height, int flags);
	~Renderer();

	void render();
};

