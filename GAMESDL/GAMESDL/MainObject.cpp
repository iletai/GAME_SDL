#include "MainObject.h"

////////////////////////////////////////////////////////////////////////////////////////////

MainObject::MainObject()
	: x_valGameObj(0)
	, y_valGameObj(0)
	//, rect{0,0,WIDTH_MAIN_OBJECT,HEIGHT_MAIN_OBJECT}
{
		rect.x = 0;
		rect.y = 0;
		rect.w = WIDTH_MAIN_OBJECT;
		rect.h = HEIGHT_MAIN_OBJECT;
}

////////////////////////////////////////////////////////////////////////////////////////////

MainObject::~MainObject()
{
}

////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////

void MainObject::HandleInputMoveObject(SDL_Event events)
{
	switch (events.key.keysym.sym)
	{
	case SDLK_UP:
		if (events.type == SDL_KEYUP)
		{
		}
		break;
	case SDLK_DOWN:
		break;
	case SDLK_RIGHT:
		break;
	case SDLK_LEFT:
		break;
	default:
		break;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////

void MainObject::HandleMoveObject()
{
}

////////////////////////////////////////////////////////////////////////////////////////////