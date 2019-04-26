#ifndef MAIN_OBJECT_H
#define MAIN_OBJECT_H

#include "CommonFunction.h"
#include "BaseObject.h"

////////////////////////////////////////////////////////////////////////////////////////////

#define WIDTH_MAIN_OBJECT 64
#define HIEGHT_MAIN_OBJECT 91

////////////////////////////////////////////////////////////////////////////////////////////

class MainObject : public BaseObject
{
public:
	MainObject();
	~MainObject();

	void HandleMove();
	void HandleInput(SDL_Event events);

private:
	int x_val;
	int y_val;

};


#endif	    //MAIN_OBJECT_H