#include <exception>
#include <iostream>

#include "Renderer.h"

int main(int arc, char* argv[])
{
	try
	{
		Renderer r(800, 600, NULL);
		r.render();
	}
	catch (std::exception e)
	{
		std::cout << e.what();
	}

	return 0;
}