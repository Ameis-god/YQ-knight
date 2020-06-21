#ifndef __BOSS_H__
#define __BOSS_H__


#include "cocos2d.h"
#include "Monster.h"


class Boss :public Monster
{
private:

public:
	virtual bool init();
	CREATE_FUNC(Boss);

	virtual void attacked(const int value);
	virtual void die();

	void setBars(Scene *s, const Point p);
	void updateHPBar();
};

#endif // !__BOSS_H__

