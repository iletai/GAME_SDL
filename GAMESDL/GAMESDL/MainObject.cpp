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
	if (events.type == SDL_KEYDOWN)
	{
		switch (events.key.keysym.sym)
		{
		case SDLK_UP:
			y_valGameObj -= HEIGHT_MAIN_OBJECT / 4;
			break;
		case SDLK_DOWN:
			y_valGameObj += HEIGHT_MAIN_OBJECT / 4;
			break;
		case SDLK_LEFT:
			x_valGameObj -= WIDTH_MAIN_OBJECT / 4;
			break;
		case SDLK_RIGHT:
			x_valGameObj += WIDTH_MAIN_OBJECT / 4;
			break;
		default:
			break;
		}
	}
	else if (events.type == SDL_KEYUP)
	{
		switch (events.key.keysym.sym)
		{
		case SDLK_UP:
			y_valGameObj += HEIGHT_MAIN_OBJECT / 4;
			break;
		case SDLK_DOWN:
			y_valGameObj -= HEIGHT_MAIN_OBJECT / 4;
			break;
		case SDLK_LEFT:
			x_valGameObj += WIDTH_MAIN_OBJECT / 4;
			break;
		case SDLK_RIGHT:
			x_valGameObj -= WIDTH_MAIN_OBJECT / 4;
			break;
		default:
			break;
		}
	}
	else if (events.type == SDL_MOUSEBUTTONDOWN)
	{
		
	}
	else if (events.type == SDL_MOUSEBUTTONUP)
	{
		 
	}
	else
	{

	}
}

////////////////////////////////////////////////////////////////////////////////////////////

void MainObject::HandleMoveObject()
{
	rect.x += x_valGameObj;
	if(rect.x < 0 || rect.x + WIDTH_MAIN_OBJECT > SCREEN_WIDTH) 
		rect.x -= x_valGameObj;
	
	rect.y += y_valGameObj;
	if(rect.y < 0 || rect.y + HEIGHT_MAIN_OBJECT > SCREEN_HEIGHT) 
		rect.x -= y_valGameObj;

}

////////////////////////////////////////////////////////////////////////////////////////////