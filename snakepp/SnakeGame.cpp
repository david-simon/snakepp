#include "SnakeGame.h"

SnakeGame::SnakeGame(Renderer& r) : renderer(r)
{
	renderer.SetGame(*this);
}

void SnakeGame::Start()
{
	renderer.Render();
}

void SnakeGame::ProcessEvent(SDL_Event& e)
{
	switch (e.type)
	{
	case SDL_EventType::SDL_QUIT:
		renderer.Quit();
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

		break;
	}
}

void SnakeGame::Draw()
{
	SDL_Rect rect = {0,0,800,600};
	SDL_FillRect(&renderer.GetSurface(), &rect, 0);

	snake.Draw(renderer.GetSurface());
}




SnakeGame::~SnakeGame()
{
}
