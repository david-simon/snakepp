#include "Pickup.h"



Pickup::Pickup(int x, int y) : position({x,y})
{
}

void Pickup::Draw(SDL_Surface & surface)
{
	SDL_Rect rect = {position.x, position.y, 10, 10};
	SDL_FillRect(&surface, &rect, 0x00ff0000);
}
