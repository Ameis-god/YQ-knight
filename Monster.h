#ifndef __MONSTER_H__
#define __MONSTER_H__


#include "cocos2d.h"
#include "MovingActor.h"


class Monster :public MovingActor
{
protected:

public:
	virtual void die();
	virtual void attacked(int value);
	virtual void updateStatus(float dt);
};

//近战怪物
class MeleeMonster :public Monster
{
protected:

public:
	virtual bool init();
	CREATE_FUNC(MeleeMonster);
};


//远程怪物
class RemoteMonster :public Monster
{
protected:

public:
	virtual bool init();
	CREATE_FUNC(RemoteMonster);
};

#endif // !__MONSTER_H__
