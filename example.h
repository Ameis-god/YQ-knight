# YQ-knight
use to create the knight game
#ifndef __EXAMPLE_H__
#define __EXAMPLE_H__

#include<iostream>
#include "cocos2d.h"
using namespace cocos2d;

//class Weapon{};
//class Buff {};
//class Talent {};

class Knight :public cocos2d::Sprite
{
private:
	int HP;//血量
	int limitHP;//生命上限
	int armor;//护甲
	int limitArmor;//护甲上限
	int MP;//蓝量
	int limitMP;//蓝量上限

	//Vector<Weapon> myWeapon;//武器栏
	//Weapon mainWeapon;//主武器
	//Weapon secondaryWeapon;//副武器

	int gold;//金币
	int movingSpeed;//移动速度
	//Vector<Buff> myBuff;//buff栏
	//Vector<Talent> myTalent;//天赋栏

public:
	
	virtual bool init();
	CREATE_FUNC(Knight);
	void die();
	void attacked(int value);

	int getHP();
	int getLimitHP();
	void changeHP(int value);//修改生命值，value为正时加血，为负时减血
	void setHPBar(Scene *s);//在场景s中添加血条
	void updateHPBar(Scene *s);//在场景s中更新血条
	

	int getArmor();
	int getLimitArmor();
	void changeArmor(int value);//修改护甲值，value为正时恢复护甲，为负时减少护甲
	void setArmorBar(Scene *s);//在场景s中添加护甲条
	void updateArmorBar(Scene *s);//在场景s中更新护甲条
	
	int getMP();
	int getLimitMP();
	void changeMP(int value);//修改魔力值，value为正时增加，为负时减少
	void setMPBar(Scene *s);//在场景s中添加魔力条
	void updateMPBar(Scene *s);//在场景s中更新魔力条

	void equipWeapon();//装备武器
	void switchWeapon();//切换武器

	void collectGold();//拾取金币
	void changeGold();//更改金币数值
	void collectMP();//拾取魔法点数

	//void takeBuff(Buff b);
	//void clearBuff(Buff b);

};




#endif // !__EXAMPLE_H__
