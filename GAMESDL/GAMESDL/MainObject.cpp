#include "MainObject.h"

////////////////////////////////////////////////////////////////////////////////////////////

MainObject::MainObject() 
	: x_val(0)
	, y_val(0)
{
	rect.x = 0;
	rect.y = 0;
	rect.w = WIDTH_MAIN_OBJECT;
	rect.h = HIEGHT_MAIN_OBJECT;
}

////////////////////////////////////////////////////////////////////////////////////////////

MainObject::~MainObject()
{

}

////////////////////////////////////////////////////////////////////////////////////////////

void MainObject::HandleMove()
{
	rect.x += x_val;
	if (rect.x < 0 || (rect.x + WIDTH_MAIN_OBJECT > SCREEN_WIDTH) )
		rect.x -= x_val;

	rect.y += y_val;
	if (rect.y < 0 || (rect.y + HIEGHT_MAIN_OBJECT > SCREEN_HEIGHT - MAP_HEIGHT))
		rect.y -= y_val;
}

////////////////////////////////////////////////////////////////////////////////////////////

void MainObject::HandleInput(SDL_Event events)
{
	//Handle move game object here
	if (events.type == SDL_KEYDOWN)
	{
		switch (events.key.keysym.sym)
		{
		case SDLK_UP:
			y_val -= WIDTH_MAIN_OBJECT / 4;
			break;
		case SDLK_DOWN:
			y_val += WIDTH_MAIN_OBJECT / 4;
			break;
		case SDLK_RIGHT:
			x_val += HIEGHT_MAIN_OBJECT / 4;
			break;
		case SDLK_LEFT:
			x_val -= HIEGHT_MAIN_OBJECT / 4;
			break;
		default:
			break;
		}
	}
	else if (events.type == SDL_KEYUP)
	{
		switch (events.key.keysym.sym)
		{
		case SDLK_UP:
			y_val += WIDTH_MAIN_OBJECT / 4;
			break;
		case SDLK_DOWN:
			y_val -= WIDTH_MAIN_OBJECT / 4;
			break;
		case SDLK_RIGHT:
			x_val -= HIEGHT_MAIN_OBJECT / 4;
			break;
		case SDLK_LEFT:
			x_val += HIEGHT_MAIN_OBJECT / 4;
			break;
		default:
			break;
		}
	}
	else if ( events.type == SDL_MOUSEBUTTONDOWN)
	{
		AmoGunObject* p_AmoOjbect = new AmoGunObject();
		if (events.button.button == SDL_BUTTON_LEFT)
		{
			p_AmoOjbect->SetWidthHeightAmor(WIDTH_LASER, HEIGHT_LASER);
			p_AmoOjbect->LoadImageByPath("laser.png",0,255,255);
			p_AmoOjbect->SetTypeAmor(AmoGunObject::AmorType::LASER);

		}
		if (events.button.button == SDL_BUTTON_RIGHT)
		{
			p_AmoOjbect->SetWidthHeightAmor(WIDTH_SPHERE, HEIGHT_SPHERE);
			p_AmoOjbect->LoadImageByPath("sphere.png",0,255,255);
			p_AmoOjbect->SetTypeAmor(AmoGunObject::AmorType::SPHERE);
		}

		p_AmoOjbect->SetRectObject(this->rect.x + 80, this->rect.y + 22);
		p_AmoOjbect->SetIsMoving(true);
		p_AmorList.push_back(p_AmoOjbect);
	}
	else if (events.type == SDL_MOUSEBUTTONUP)
	{

	}
}

////////////////////////////////////////////////////////////////////////////////////////////

void MainObject::SetAmoList(std::vector<AmoGunObject*> amoList)
{
	p_AmorList = amoList;
}

////////////////////////////////////////////////////////////////////////////////////////////

std::vector<AmoGunObject*> MainObject::GetAmorList() const
{
	return p_AmorList;
}

////////////////////////////////////////////////////////////////////////////////////////////