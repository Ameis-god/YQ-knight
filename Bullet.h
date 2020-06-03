#ifndef _Bullet_H_
#define _Bullet_H_
#include"cocos2d.h"
USING_NS_CC;
using namespace cocos2d;
#define SPEED 0.5f
#define Capacity 10
class Bullet :public Node {
public:
	Bullet();//子单属性
	~Bullet();
	void start(Sprite* monsterSprite, Sprite* rpkBullet,Sprite* rpk);
	void autoBulletShoot(Sprite* spriteOne, Sprite* spriteTwo, Sprite* spriteThree);//先规定一个子弹 不同自担就是改变伤害值和图片
	void aimBulletShoot(Sprite* spriteOne, Sprite* spriteTwo, Sprite* spriteThree);
	void setUsed(Sprite* spriteOne, Sprite* spriteTwo);
	void setBulletPos(Sprite* spriteOne, Sprite* spriteTwo);
	void setWeaponPos(Sprite* spriteOne);
	//static Bullet* create(const std::string& filename);
private:
	float atkBulletValue;
	float bulletSpeed;
	int  areUsed;//是否使用
	bool  isAimed;//是否命中
	int bulletCapacity;
};
#endif // !_TollgateScene_H_
#pragma once#pragma once
