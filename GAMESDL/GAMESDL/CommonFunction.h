#ifndef COMMONFUNCTION_H
#define COMMONFUNCTION_H

#include <Windows.h>	  
#include <string>

#include <SDL.h>
#include <SDL_image.h>


////////////////////////////////////////////////////////////////////////////////////////////
const		int		SCREEN_WIDTH	= 1440;
const		int		SCREEN_HEIGHT	= 960;
const		int		MAP_HEIGHT		= 200;
const	    int		SCREEN_BPP		= 32;

static SDL_Surface			*g_screen = NULL;
static SDL_Surface			*g_bkground = NULL;
static SDL_Event			g_event;

static int POS_OBJECT_X = 400;
static int POS_OBJECT_Y = 300;

#define PLAYER_COLOR	0
#define AMOR_COLOR		1

////////////////////////////////////////////////////////////////////////////////////////////

namespace SDLCommonFunc
{
	SDL_Surface* LoadImageByPath(std::string file_Path, int firtsRgb, int secondRgb, int thirdRgb);
	void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
	void CleanUp();
}
#endif	 //COMMONFUNCTION_H