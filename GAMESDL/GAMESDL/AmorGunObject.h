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

	void    HandleMoveAmor();
	void    HandleInputActionAmor(SDL_Event events);

	int		getTypeAmor() const;
	void	SetTypeAmor(const int& type);

	bool	getIsMovingAmor() const;
	void	setIsMoving(bool isMovingAmor);
	void    setWidthHeightAmor(const int& width, const int& height);
private:
	int		x_valAmor;
	int		y_valAmor;
	bool	isMovingAmor;
	int		amorType;
};


#endif	  //AMO_GUN_OBJECT_H