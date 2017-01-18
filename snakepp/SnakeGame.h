#pragma once
#include "Renderer.h"
#include "Game.h"
#include "Snake.h"
#include "Pickup.h"

class SnakeGame : public Game
{
	Snake snake;
	Renderer renderer;
	Pickup p;

	SnakeGame(const SnakeGame&);

public:
	SnakeGame();
	~SnakeGame();

	void ProcessEvent(SDL_Event&);
	void Draw();
	void Start();

	inline Pickup& GetPickup() { return p; };
	inline Snake& GetSnake() { return snake; };
};