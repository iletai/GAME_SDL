#include "EnemyObject.h"

////////////////////////////////////////////////////////////////////////////////////////////

EnemyObject::EnemyObject()
	: x_valEnemy(0)
	, y_valEnemy(0)
{
	rect.x = 0;
	rect.y = 0;
	rect.w = WIDTH_ENEMY;
	rect.h = HEIGHT_ENEMY;
}

////////////////////////////////////////////////////////////////////////////////////////////

EnemyObject::~EnemyObject()
{

}

////////////////////////////////////////////////////////////////////////////////////////////

void EnemyObject::HandleMoveEnemy(const int& x_screenBorder, const int& y_screenBorder)
{
	rect.y += y_valEnemy;

	int rand_y_ValEnemy = rand() % 400;
	if (rand_y_ValEnemy > SCREEN_HEIGHT)
	{
		rand_y_ValEnemy = SCREEN_WIDTH*0.3 - 300;
	}
	if (rect.y > x_screenBorder)
	{
		rect.x = rand_y_ValEnemy;
		rect.y = 0;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////

void EnemyObject::HandleInputActionEnemy(SDL_Event events)
{

}

////////////////////////////////////////////////////////////////////////////////////////////

void EnemyObject::Set_X_ValueEnemy(const int& val)
{
	x_valEnemy = val;
}

////////////////////////////////////////////////////////////////////////////////////////////

void EnemyObject::Set_Y_ValueEnemy(const int& val)
{
	y_valEnemy = val;
}

////////////////////////////////////////////////////////////////////////////////////////////

int EnemyObject::Get_X_ValueEnemy() const
{
	return x_valEnemy;
}

////////////////////////////////////////////////////////////////////////////////////////////

int EnemyObject::Get_Y_ValueEnemy() const
{
	return y_valEnemy;
}

////////////////////////////////////////////////////////////////////////////////////////////

void EnemyObject::SetEnemyAmoList(std::vector<AmoGunObject*> amoEnemyList)
{
	p_EnemyAmorList = amoEnemyList;
}

////////////////////////////////////////////////////////////////////////////////////////////

std::vector<AmoGunObject*> EnemyObject::GetEnemyAmorList() const
{
	return p_EnemyAmorList;
}

////////////////////////////////////////////////////////////////////////////////////////////

void EnemyObject::InitAmoEnemy(AmoGunObject* p_amoEnemy)
{
	if (p_amoEnemy)
	{
		bool ret = p_amoEnemy->LoadImageByPath("sphere.png", 00000, 00000, 00000);
		if (ret)
		{
			p_amoEnemy->SetIsMoving(true);
			p_amoEnemy->SetWidthHeightAmor(WIDTH_SPHERE, HEIGHT_SPHERE);
			p_amoEnemy->SetTypeAmor(AmoGunObject::AmorType::SPHERE);
			p_amoEnemy->SetRectObject(rect.x, rect.y + rect.h*0.5);
			p_EnemyAmorList.push_back(p_amoEnemy);
				
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////

void EnemyObject::MakeAmorEnemy(SDL_Surface* des, const int& x_limitEnemy, const int& y_limitEnemy)
{
	for (int i = 0; i < p_EnemyAmorList.size(); i++)
	{
		AmoGunObject* p_amo = p_EnemyAmorList.at(i);
		if (p_amo)
		{
			if (p_amo->GetIsMovingAmor())
			{
				p_amo->ShowObject(des);
				p_amo->HandleMoveTopToDown();
			}
			else
			{
				p_amo->SetIsMoving(true);
				p_amo->SetRectObject(rect.x, rect.y + rect.h*0.5);
			}
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////