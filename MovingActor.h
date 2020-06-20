#ifndef __MOVINGACTOR_H__
#define __MOVINGACTOR_H__

#include<iostream>
#include<vector>
#include "cocos2d.h"
#include "Buff.h"
using namespace cocos2d;

class MovingActor :public Sprite
{
protected:
	int HP;//当前血量
	int limitHP;//血量上限
	int AD;//攻击力
	int movingSpeed;//移动速度

	Scene *currentScene;

	std::vector<Buff> myBuff;//buff栏
public:
	virtual bool init() = 0;//创建
	virtual void die() = 0;//死亡
	virtual void attacked(int value) = 0;//受到攻击
	virtual void updateStatus(float dt) = 0;//更新状态
	
	bool takeBuff(Buff b);//获得buff
	void clearBuff(float dt);
};


#endif // !__MOVINGACTOR_H__


