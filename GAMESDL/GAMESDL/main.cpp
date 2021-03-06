#include "CommonFunction.h"
#include "MainObject.h"
#include "EnemyObject.h"
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

	g_bkground = SDLCommonFunc::LoadImageByPath("BG.jpg", 00000, 00000, 00000);
	if ( g_bkground == NULL )
		return 0;
	
	//MAIN OBJECT
	MainObject plane_Object;
	plane_Object.SetRectObject(400, 220);
	bool isRect = plane_Object.LoadImageByPath("airplane-icon.png", 00000, 00000, 00000);
	if (!isRect)
		return 0;

	//ENEMY OBJECT
	EnemyObject* p_Enemys = new EnemyObject[NUM_ENEMYS];
	for (int  t = 0; t < NUM_ENEMYS; t++)
	{
		EnemyObject* p_Enemy = (p_Enemys + t);
		if (p_Enemy)
		{
			bool ret = p_Enemy->LoadImageByPath("enemyRock.png", 00000, 00000, 00000);
			if (!ret)
				return 0;

			int rand_y_ValEnemy = rand() % 400;
			if (rand_y_ValEnemy > SCREEN_HEIGHT)
			{
				rand_y_ValEnemy = SCREEN_HEIGHT*0.3 - 200;
			}

			p_Enemy->SetRectObject(rand_y_ValEnemy, 0+t*500);
			p_Enemy->Set_Y_ValueEnemy(5);
			AmoGunObject* p_AmoEnemy = new AmoGunObject();
			p_Enemy->InitAmoEnemy(p_AmoEnemy);
		}
	}

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

		//Implement Main Object
		plane_Object.ShowObject(g_screen);
		plane_Object.HandleMove();
		plane_Object.MakeAmoObject(g_screen);

		//Implement ENEMY SHOW 
		for (int tt = 0; tt < NUM_ENEMYS; tt++)
		{
			EnemyObject* p_Enemy = (p_Enemys + tt);
			if (p_Enemy)
			{
				p_Enemy->ShowObject(g_screen);
				p_Enemy->HandleMoveEnemy(SCREEN_WIDTH, SCREEN_HEIGHT);
				p_Enemy->MakeAmorEnemy(g_screen, SCREEN_WIDTH, SCREEN_HEIGHT);
			}
		}

		//Update Screen
		if ( SDL_Flip(g_screen)  == -1)
		{						  
			return 0;
		}
	}

	delete[] p_Enemys;

	SDLCommonFunc::CleanUp(); //call to free value pointer
	SDL_Quit();

	return 1;
}

////////////////////////////////////////////////////////////////////////////////////////////
