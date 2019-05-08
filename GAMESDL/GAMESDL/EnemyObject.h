#ifndef ENEMY_OBJECT_H
#define ENEMY_OBJECT_H

#include "BaseObject.h"
#include "AmorGunObject.h"
#include <vector>

#define		WIDTH_ENEMY			80
#define		HEIGHT_ENEMY		30

const int UNDER_LIMMIT_ENEMY =	300;

class EnemyObject : public BaseObject
{
public:
	EnemyObject();
	~EnemyObject();

	void	HandleMoveEnemy(const int& x_screenBorder, const int& y_screenBorder);
	void	HandleInputActionEnemy(SDL_Event events);
	void	Set_X_ValueEnemy(const int& val);
	void	Set_Y_ValueEnemy(const int& val);
	int		Get_X_ValueEnemy() const;
	int		Get_Y_ValueEnemy() const;
	void	InitAmoEnemy(AmoGunObject* p_amoEnemy);
	void	MakeAmorEnemy(SDL_Surface* des, const int& x_limitEnemy, const int& y_limitEnemy);
	void						SetEnemyAmoList(std::vector<AmoGunObject*> amoEnemyList);
	std::vector<AmoGunObject*>	GetEnemyAmorList() const;
private:
	int		x_valEnemy;
	int		y_valEnemy;
	
	std::vector<AmoGunObject*> p_EnemyAmorList;

};

#endif //!ENEMY_OBJECT_H