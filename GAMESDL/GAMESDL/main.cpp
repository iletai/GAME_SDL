#include <Windows.h>	 ]
#include <string>

#include <SDL.h>
#include <SDL_image.h>
#undef main

////////////////////////////////////////////////////////////////////////////////////////////

const		int		SCREEN_WIDTH			= 1200;
const		int		SCREEN_HEIGHT			= 600;
const	    int		SCREEN_BPP				= 32;

SDL_Surface			*g_screen				= NULL;
SDL_Surface			*g_bkground				= NULL;
SDL_Event			g_event;

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

SDL_Surface* LoadImageByPath(std::string file_Path)
{
	SDL_Surface *load_Image		= NULL;
	SDL_Surface *optimize_Image = NULL;

	load_Image = IMG_Load(file_Path.c_str());
	if (load_Image != NULL)
	{
		optimize_Image = SDL_DisplayFormat(load_Image);
		SDL_Surface(load_Image);
	}

	return optimize_Image;
}

////////////////////////////////////////////////////////////////////////////////////////////

void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y)
{
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface( src, NULL, des, &offset );
}

////////////////////////////////////////////////////////////////////////////////////////////

void CleanUp()
{
	SDL_FreeSurface(g_screen);
	SDL_FreeSurface(g_bkground);
}

////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	bool is_quitGame = false;
	if ( Init() == false )
		return 0;

	g_bkground = LoadImageByPath("JZBW2722.PNG");
	if ( g_bkground == NULL )
	{
		return 0;
	}

	ApplySurface(g_bkground, g_screen, 0, 0);

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

	CleanUp(); //call to free value pointer
	SDL_Quit();

	return 1;
}