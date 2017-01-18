#include <exception>
#include <iostream>

#include "Renderer.h"
#include "SnakeGame.h"

int main(int arc, char* argv[])
{
	try
	{
		SnakeGame& game = (SnakeGame&)GetGameObject();

		game.Start();
	}
	catch (std::exception e)
	{
		std::cout << e.what();
	}

	return 0;
}