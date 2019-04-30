#ifndef MAIN_OBJECT_H
#define MAIN_OBJECT_H

#include "BaseObject.h"
#include "CommonFunction.h"

#define WIDTH_MAIN_OBJECT			90
#define HEIGHT_MAIN_OBJECT			80

class MainObject : public BaseObject
{
public:
	MainObject();
	~MainObject();

	void HandleMoveObject();
	void HandleInputMoveObject(SDL_Event events);

private:
	SDL_Rect rectObject;
	int x_valGameObj;
	int y_valGameObj;
};

#endif //MAIN_OBJECT_H
