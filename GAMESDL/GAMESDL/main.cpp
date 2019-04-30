#include "CommonFunction.h"
#include "MainObject.h"
#undef main

using namespace SDLCommonFunc;


////////////////////////////////////////////////////////////////////////////////////////////

bool Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
		return false;

	g_screen = SDL_SetVideoMode(
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		SCREEN_BPP,
		SDL_SWSURFACE
	);
	if (g_screen == NULL)
		return false;

	return true;
}

////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	bool is_quitGame = false;
	if (Init() == false)
		return 0;

	g_bkground = SDLCommonFunc::LoadImageByPath("BG.jpg");
	if (g_bkground == NULL)
		return 0;
	SDLCommonFunc::ApplySurface(g_bkground, g_screen, 0, 0);
	
	MainObject* p_PlaneObject = new MainObject();
	p_PlaneObject->SetRectObject(300, 300);
	p_PlaneObject->LoadImageByPath("airplane-3.png");
	if (p_PlaneObject == NULL)
		return 0;
	p_PlaneObject->ShowObject(g_screen);

	while (!is_quitGame)
	{
		while (SDL_PollEvent(&g_event))
		{
			if (g_event.type == SDL_QUIT)
			{
				is_quitGame = true;
				break;
			}
		}
		if (SDL_Flip(g_screen) == -1)
		{
			return 0;
		}
	}

	SDLCommonFunc::CleanUp(); //call to free value pointer
	SDL_Quit();

	return 1;
}

////////////////////////////////////////////////////////////////////////////////////////////