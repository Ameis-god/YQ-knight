#ifndef _Bullet_H_
#define _Bullet_H_
#include"cocos2d.h"
#include"Monster.h"
#include"TMX_Map.h"
#include <vector>
#include"MonsterManager.h"
USING_NS_CC;
using namespace cocos2d;
using namespace std;
#define SPEED 0.5f
#define Capacity 200
class Monster;
class Bullet :public Node {
public:
	Bullet();//子单属性
	~Bullet();
	void creatBullet();
	void  start(MonsterManager* monsterSprite, Knight* hero);
	void  startOne(MonsterManager* monsterSprite, Knight* hero);
	void  startTwo(MonsterManager* monsterSprite, Knight* hero);
	void autoBulletShoot(Monster* spriteOne, Sprite* spriteTwo, Sprite* spriteThree);//先规定一个子弹 不同自担就是改变伤害值和图片
	void aimBulletShoot(MonsterManager* spriteOne, Knight* spriteThree);
	void aimBulletShootOne(MonsterManager* spriteOne, Knight* spriteThree);
	void aimBulletShootTwo(MonsterManager* spriteOne, Knight* spriteThree);
	void setUsed(Monster* spriteOne);
	void setBulletPos(Knight* spriteOne);
	void setBulletPosOne(Knight* spriteOne);
	void setBulletPosTwo(Knight* spriteOne);
	void setWeaponPos(Sprite* spriteOne);
	void startBuff(Monster* monsterSprite, Sprite* hero, Point a);
	void setBulletPosBuff(Sprite* spriteOne, Point a);
	Point bulletPos();
	CREATE_FUNC(Bullet);
	void hit();
	void bindSprite(Sprite* sprite);
	void bindKnight(Knight* sprite);
	void bindMonster(Monster* monster);
	void bindMonsterManager(MonsterManager* monster);
	void bindmapOperator(mapOperator* mapOne);
	void show();
	void hide();
	void wallUpdate(float dt);
	virtual void update(float dt);
	void wallUpdateOne(float dt);
	virtual void updateOne(float dt);
	void wallUpdateTwo(float dt);
	virtual void updateTwo(float dt);
	void tripleAction(MonsterManager* monsterSprite, Knight* hero);
	void singleAction(MonsterManager* monsterSprite, Knight* hero);
	int iAttacked();
	void bulletShoot(MonsterManager* monster, MenuItemImage* pLabel, Knight* hero);
	//	void hit();
		//static Bullet* create(const std::string& filename);
private:
	int iAttack;
	float atkBulletValue;
	float bulletSpeed;
	int  areUsed;//是否使用
	int  areUsedOne;
	int  areUsedTwo;
	bool  isAimed;//是否命中
	int bulletCapacity;
	Point b;
	int iHP;
	vector<Sprite*>bulletArr;
	vector<Sprite*>bulletArrOne;
	vector<Sprite*>bulletArrTwo;
	Sprite* bullet;
	Knight* heroOne;
	Monster* monster;
	mapOperator* map;
	int num[Capacity];
	int numOne[Capacity];
	int numTwo[Capacity];
	int initial;
	int initialOne;
	int initialTwo;
	vector<Monster*> monsterArr;
	vector<Monster*> monsterArrOne;
	vector<Monster*> monsterArrTwo;
	MonsterManager* monsterMgr;
	MonsterManager* monsterMgrOne;
	MonsterManager* monsterMgrTwo;
};
#endif // !_TollgateScene_H_
#pragma once

#pragma once
