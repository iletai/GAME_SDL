#include "CommonFunction.h"
#undef main

#include "MainObject.h"

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

	g_bkground = SDLCommonFunc::LoadImageByPath("BG.jpg", 00000, 00000, 00000);
	if ( g_bkground == NULL )
		return 0;
	
	MainObject plane_Object;
	plane_Object.SetRectObject(400, 220);
	bool isRect = plane_Object.LoadImageByPath("airplane-3.png", 00000, 00000, 00000);
	if (!isRect)
		return 0;

	while (!is_quitGame)
	{
		while ( SDL_PollEvent(&g_event) )
		{
			if (g_event.type == SDL_QUIT)
			{
				is_quitGame = true;
				break;
			}
			plane_Object.HandleInput(g_event);
		}

		SDLCommonFunc::ApplySurface(g_bkground, g_screen, 0, 0);

		plane_Object.ShowObject(g_screen);
		plane_Object.HandleMove();

		for (int i = 0; i < plane_Object.GetAmorList().size(); i++)
		{
			std::vector<AmoGunObject*> amo_List = plane_Object.GetAmorList();
			AmoGunObject* p_amo = amo_List.at(i);
			if (p_amo != NULL)
			{
				if (p_amo->GetIsMovingAmor())
				{
					p_amo->ShowObject(g_screen);
					p_amo->HandleMoveAmor(SCREEN_WIDTH, SCREEN_HEIGHT);
				}
				else
				{
					if (p_amo != NULL)
					{
						amo_List.erase(amo_List.begin() + i);
						plane_Object.SetAmoList(amo_List);
						delete p_amo;
						p_amo = NULL;
					}
				}
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
