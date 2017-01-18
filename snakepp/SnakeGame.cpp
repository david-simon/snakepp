#include <ctime>
#include <iostream>
#include "SnakeGame.h"

SnakeGame::SnakeGame() : p(), renderer(800, 600, NULL)
{
}

void SnakeGame::Start()
{
	p.Generate();
	renderer.Render();
}

void SnakeGame::ProcessEvent(SDL_Event& e)
{
	switch (e.type)
	{
	case SDL_EventType::SDL_QUIT:
		renderer.Stop();
		break;
	case SDL_EventType::SDL_KEYDOWN:
		if (e.key.keysym.sym == SDLK_DOWN)
			snake.SetDirection(snake.SOUTH);
		else if (e.key.keysym.sym == SDLK_UP)
			snake.SetDirection(snake.NORTH);
		else if (e.key.keysym.sym == SDLK_RIGHT)
			snake.SetDirection(snake.EAST);
		else if (e.key.keysym.sym == SDLK_LEFT)
			snake.SetDirection(snake.WEST);
		else if (e.key.keysym.sym == SDLK_SPACE)
			snake.AddPart();
		else if (e.key.keysym.sym == SDLK_ESCAPE)
			renderer.Stop();

		break;
	}
}

void SnakeGame::Draw()
{
	SDL_Rect rect = {0,0,800,600};
	SDL_FillRect(&renderer.GetSurface(), &rect, 0);

	p.Draw(renderer.GetSurface());

	
	snake.Draw(renderer.GetSurface());

}


SnakeGame::~SnakeGame()
{
}


Game& GetGameObject()
{
	static SnakeGame game;
	return game;
}