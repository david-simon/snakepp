#pragma once
#include "Renderer.h"
#include "Game.h"
#include "Snake.h"
#include "Pickup.h"

class SnakeGame : public Game
{
	Snake snake;
	Renderer& renderer;
	Pickup p;

public:
	SnakeGame(Renderer& r);
	~SnakeGame();

	void ProcessEvent(SDL_Event&);
	void Draw();
	void Start();
	bool CheckCollision();
	bool CheckPickup();
	void GeneratePickup();
};

