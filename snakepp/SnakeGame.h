#pragma once
#include "Renderer.h"
#include "Game.h"

class SnakeGame : public Game
{
	Renderer& renderer;

public:
	SnakeGame(Renderer& r);
	~SnakeGame();

	void ProcessEvent(SDL_Event&);
	void Draw();
	void Start();
};

