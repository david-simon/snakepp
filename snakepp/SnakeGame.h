#pragma once
#include "Renderer.h"
#include "Game.h"
#include "Snake.h"

class SnakeGame : public Game
{
	Snake snake;
	Renderer& renderer;

public:
	SnakeGame(Renderer& r);
	~SnakeGame();

	void ProcessEvent(SDL_Event&);
	void Draw();
	void Start();
};

