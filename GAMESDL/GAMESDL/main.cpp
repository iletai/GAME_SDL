#include "CommonFunction.h"
#undef main

using namespace SDLCommonFunc;


////////////////////////////////////////////////////////////////////////////////////////////

bool Init()
{
	if ( SDL_Init(SDL_INIT_EVERYTHING)  == -1 )
		return false;

	g_screen = SDL_SetVideoMode(
								SCREEN_WIDTH,
								SCREEN_HEIGHT,
								SCREEN_BPP,
								SDL_SWSURFACE
								);
	if ( g_screen == NULL )
		return false;

	return true;
}

////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	bool is_quitGame = false;
	if ( Init() == false )
		return 0;

	g_bkground = SDLCommonFunc::LoadImageByPath("JZBW2722.PNG");
	//g_object   = LoadImageByPath("airplane-3.png");
	if ( g_bkground == NULL )
		return 0;
	// if (g_object == NULL)
	//	return 0;
	SDLCommonFunc::ApplySurface(g_bkground, g_screen, 0, 0);
	//ApplySurface(g_object, g_screen, POS_OBJECT_X, POS_OBJECT_Y);

	while (!is_quitGame)
	{
		while ( SDL_PollEvent(&g_event) )
		{
			if (g_event.type == SDL_QUIT)
			{
				is_quitGame = true;
				break;
			}
		}
		if ( SDL_Flip(g_screen)  == -1)
		{						  
			return 0;
		}
	}

	SDLCommonFunc::CleanUp(); //call to free value pointer
	SDL_Quit();

	return 1;
}

////////////////////////////////////////////////////////////////////////////////////////////
