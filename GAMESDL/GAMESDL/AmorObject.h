#ifndef AMOR_OBJECT_H
#define AMOR_OBJECT_H

#include "BaseObject.h"
#include "MainObject.h"

#define		WIDTH_AMOR_LASER	20
#define		HEIGHT_AMOR_LASER	20
#define		WIDTH_AMOR_SPHERE	20
#define		HEIGHT_AMOR_SPHERE	20

class AmorObject : public MainObject
{
public:
	enum AMOR_TYPE
	{
		LASER	= 0,
		SPHERE	= 1,
		NONE	= 2
	};

	AmorObject();
	~AmorObject();
	unsigned int GetAmorType() const;
	void HandleMoveAmorInput(SDL_Event events_Amor, SDL_Rect rect_Amor);
	void HanleMoveAmor(const int x_BorderAmor, const int y_BorderAmor);
private:
	bool			isMove;
	int				x_ValAmor;
	int				y_ValAmor;
	unsigned int	m_AmorType;
 };


#endif // !AMOR_OBJECT_H
