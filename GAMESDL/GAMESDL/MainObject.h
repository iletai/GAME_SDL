#ifndef MAIN_OBJECT_H
#define MAIN_OBJECT_H

#include "CommonFunction.h"
#include "BaseObject.h"
#include "AmorGunObject.h"
#include <vector>

////////////////////////////////////////////////////////////////////////////////////////////

#define WIDTH_MAIN_OBJECT		64
#define HIEGHT_MAIN_OBJECT		91

////////////////////////////////////////////////////////////////////////////////////////////


class MainObject : public BaseObject
{
public:
	MainObject();
	~MainObject();

	void HandleMove();
	void HandleInput(SDL_Event events);
	void MakeAmoObject(SDL_Surface* des);

	void SetAmoList(std::vector<AmoGunObject*> amoList);
	std::vector<AmoGunObject*> GetAmorList() const;
private:
	int x_val;
	int y_val;

	std::vector<AmoGunObject*> p_AmorList;
};


#endif	    //MAIN_OBJECT_H