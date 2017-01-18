#include <ctime>
#include <cstdlib>
#include <list>

#include "SnakeGame.h"
#include "Pickup.h"

Pickup::Pickup()
{
}

void Pickup::Generate()
{
	srand(time(NULL));

	bool occupied;
	do
	{
		occupied = false;

		position = { (rand() % 9) * 100, (rand() % 7) * 100 };
		if (position.x >= 800)
			position.x -= 10;
		if (position.y >= 600)
			position.y -= 10;

		std::list<SDL_Point> snakeBody = ((SnakeGame&)GetGameObject()).GetSnake().GetBody();

		for (auto it = snakeBody.begin(); it != snakeBody.end(); ++it)
		{
			if (position.x == it->x && position.y == it->y)
			{
				occupied = true;
				break;
			}
		}

	} while (occupied);
}

void Pickup::Draw(SDL_Surface & surface)
{
	SDL_Rect rect = {position.x, position.y, 10, 10};
	SDL_FillRect(&surface, &rect, 0x00ff0000);
}
