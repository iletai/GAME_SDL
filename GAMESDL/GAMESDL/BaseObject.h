#ifndef BASE_OBJECT_H
#define BASE_OBJECT_H

#include "CommonFunction.h"

class BaseObject
{
public: 
	BaseObject();
	~BaseObject();

	void ShowObject(SDL_Surface *des);
	bool LoadImageByPath(const char *file_namePath, int firtsRgb, int secondRgb, int thirdRgb);
	void SetRectObject(const int& x,const int& y);
	SDL_Rect		GetRectObject();
	SDL_Surface*		GetObject();
protected:
	SDL_Rect			rect;
	SDL_Surface			*p_object;
};

#endif //BASE_OBJECT_H