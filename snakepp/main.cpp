#include <exception>
#include <iostream>

#include "Renderer.h"
#include "SnakeGame.h"

int main(int arc, char* argv[])
{
	try
	{
		Renderer r(800, 600, NULL);
		SnakeGame game(r);
		game.Start();
	}
	catch (std::exception e)
	{
		std::cout << e.what();
	}

	return 0;
}