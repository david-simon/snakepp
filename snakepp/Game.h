#pragma once
#include <SDL.h>

class Game
{
public:
	virtual void Draw() = 0;
	virtual void ProcessEvent(SDL_Event&) = 0;
	virtual void Start() = 0;
};

Game& GetGameObject();
