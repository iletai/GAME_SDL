#include <Windows.h>	 ]
#include <string>

#include <SDL.h>
#include <SDL_image.h>
#undef main

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

int main()
{
	SDL_Surface *screen;
	SDL_Surface *image;

	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
		return 1;
	
	screen = SDL_SetVideoMode(1280, 1024, 32, SDL_SWSURFACE);
	image = LoadImageByPath("JZBW2722.PNG");

	SDL_BlitSurface(image, NULL, screen, NULL);

	SDL_Flip(screen);
	SDL_Delay(5000);
	SDL_FreeSurface(image);
	SDL_Quit();

	return 0;
}