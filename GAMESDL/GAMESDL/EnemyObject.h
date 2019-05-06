#ifndef ENEMY_OBJECT_H
#define ENEMY_OBJECT_H

#include "BaseObject.h"

#define WIDTH_ENEMY		80
#define HEIGHT_ENEMY	30

class EnemyObject : public BaseObject
{
public:
	EnemyObject();
	~EnemyObject();

	void	HandleMoveEnemy(const int& x_screenBorder, const int& y_screenBorder);
	void	HandleInputActionEnemy(SDL_Event events);
	void	SetXValueEnemy(const int& val);
	void	SetYValueEnemy(const int& val);
	int		GetXValueEnemy() const;
	int		GetYValueEnemy() const;

private:
	int		x_valEnemy;
	int		y_valEnemy;

};

#endif //!ENEMY_OBJECT_H