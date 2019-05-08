#ifndef AMO_GUN_OBJECT_H
#define AMO_GUN_OBJECT_H

#include "BaseObject.h"

#define		WIDTH_LASER			35
#define		HEIGHT_LASER		5
#define		WIDTH_SPHERE		10
#define		HEIGHT_SPHERE		4

class AmoGunObject : public BaseObject
{
public: 
	AmoGunObject();
	~AmoGunObject();

	enum AmorType
	{
		NONE = 0,
		LASER,
		SPHERE
	};

	void    HandleMoveAmor(const int& x_screenBorder, const int& y_screenBorder);
	void    HandleInputActionAmor(SDL_Event events);
	void	HandleMoveTopToDown();
	int		GetTypeAmor() const;
	void	SetTypeAmor(const int& type);

	bool	GetIsMovingAmor() const;
	void	SetIsMoving(bool isMove);
	void    SetWidthHeightAmor(const int& width, const int& height);
	void	Set_X_ValAmor(const int& valAmor);
	int		Get_X_ValAmor() const;
	void	Set_Y_ValAmor(const int& valAmor);
	int		Get_Y_ValAmor()	const;
private:
	int		x_valAmor;
	int		y_valAmor;
	bool	isMovingAmor;
	int		amorType;
};


#endif	  //AMO_GUN_OBJECT_H