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
	}
}

void SnakeGame::Draw()
{

}




SnakeGame::~SnakeGame()
{
}
