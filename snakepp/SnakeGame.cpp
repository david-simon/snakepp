#include <ctime>
#include "SnakeGame.h"

SnakeGame::SnakeGame(Renderer& r) : renderer(r), p(0,0)
{
	srand(time(NULL));
	GeneratePickup();
	renderer.SetGame(*this);
}

void SnakeGame::Start()
{
	renderer.Render();
}

void SnakeGame::GeneratePickup()
{
	bool occupied;
	do
	{
		occupied = false;

		p.position = { (rand() % 9) * 100, (rand() % 7) * 100 };
		if (p.position.x >= 800)
			p.position.x -= 10;
		if (p.position.y >= 600)
			p.position.y -= 10;

		std::list<SDL_Point> snakeBody = snake.GetBody();

		for (auto it = snakeBody.begin(); it != snakeBody.end(); ++it)
		{
			if (p.position.x == it->x && p.position.y == it->y)
			{
				occupied = true;
				break;
			}
		}

	} while (occupied);
}

bool SnakeGame::CheckPickup()
{
	SDL_Point head = snake.GetBody().back();
	return head.x == p.position.x && head.y == p.position.y;
}

bool SnakeGame::CheckCollision()
{
	std::list<SDL_Point> snakeBody = snake.GetBody();

	SDL_Point head = snakeBody.back();


	if (head.x < 0 || head.y < 0 || head.x >= 800 || head.y >= 600)
		return true;

	for (auto it = snakeBody.begin(); it != (--snakeBody.end()); ++it)
	{
		if (head.x == it->x && head.y == it->y)
			return true;
	}
	
	return false;
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
		else if (e.key.keysym.sym == SDLK_ESCAPE)
			renderer.Quit();

		break;
	}
}

void SnakeGame::Draw()
{
	SDL_Rect rect = {0,0,800,600};
	SDL_FillRect(&renderer.GetSurface(), &rect, 0);

	p.Draw(renderer.GetSurface());

	snake.Move();
	snake.Draw(renderer.GetSurface());

	if (CheckCollision())
	{
		snake.kill();
	}
	else if (CheckPickup())
	{
		snake.AddPart();
		GeneratePickup();
	}

}


SnakeGame::~SnakeGame()
{
}
