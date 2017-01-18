#include "Renderer.h"
#include <exception>


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

	surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
	if (surface == nullptr)
		throw new std::exception("Failed to create surface");
}

void Renderer::Render()
{
	while (!quit)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e))
			GetGameObject().ProcessEvent(e);

		GetGameObject().Draw();

		SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, surface);

		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, tex, NULL, NULL);
		SDL_RenderPresent(renderer);

		SDL_DestroyTexture(tex);
	}
}


void Renderer::Quit()
{
	quit = true;
}

SDL_Surface & Renderer::GetSurface()
{
	return *surface;
}

Renderer::~Renderer()
{
	if (win != nullptr)
		SDL_DestroyWindow(win);

	if (renderer != nullptr)
		SDL_DestroyRenderer(renderer);

	SDL_Quit();
}