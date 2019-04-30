#include "CommonFunction.h"

////////////////////////////////////////////////////////////////////////////////////////////

SDL_Surface* SDLCommonFunc::LoadImageByPath(std::string file_Path)
{
	SDL_Surface *load_Image = NULL;
	SDL_Surface *optimize_Image = NULL;

	load_Image = IMG_Load(file_Path.c_str());
	if (load_Image != NULL)
	{
		optimize_Image = SDL_DisplayFormat(load_Image);
		SDL_Surface(load_Image);
		if (optimize_Image != NULL)
		{
			UINT32 color_key = SDL_MapRGB(optimize_Image->format, 000000, 000000, 000000);
			SDL_SetColorKey(optimize_Image, SDL_SRCCOLORKEY, color_key);
		}
	}

	return optimize_Image;
}

////////////////////////////////////////////////////////////////////////////////////////////

void SDLCommonFunc::ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y)
{
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(src, NULL, des, &offset);
}

////////////////////////////////////////////////////////////////////////////////////////////

void SDLCommonFunc::CleanUp()
{
	SDL_FreeSurface(g_screen);
	SDL_FreeSurface(g_bkground);
}

////////////////////////////////////////////////////////////////////////////////////////////