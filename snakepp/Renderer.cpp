#include "Renderer.h"
#include <exception>
#include <iostream>


Renderer::Renderer(int width, int height, int flags)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		throw new std::exception("Failed to initalize SDL");


	win = SDL_CreateWindow("Snake++", 100, 100, width, height, flags);
	if (win == nullptr)
		throw new std::exception("Failed to create window");

	renderer = SDL_CreateRenderer(win, -1, NULL);
	if (renderer == nullptr)
		throw new std::exception("Failed to create SDL renderer");


}

void Renderer::render()
{
	SDL_Event e;
	while (SDL_WaitEvent(&e))
	{
		if (e.type == SDL_EventType::SDL_QUIT)
			break;
	}
}

Renderer::~Renderer()
{
	SDL_Quit();
}