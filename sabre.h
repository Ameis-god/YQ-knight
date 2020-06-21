#ifndef _SABRE_H_
#define _SABRE_H_

#include"cocos2d.h"
#include"MonsterManager.h"
#include"Monster.h"

#include"TMX_Map.h"
#include <vector>
#include"Knight.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
using namespace cocos2d;
using namespace std;
#define SPEED 0.5f
#define Capacity 10

class Sabre :public Sprite {
public:
	void sabreinit(MonsterManager* monsterOne, Knight* knight, mapOperator* mapO);
	CREATE_FUNC(Sabre);
	void isLanched(int n);
	void bindMonster(MonsterManager* monsterOne);
	void bindMonster(mapOperator* mapO);
	void bindSprite();
	int aimMon();
	void update(float dt);
	void switchSabre();
	int iAttacked();
	void bindHero(Knight*);
private:
	int iAttack;
	int isLanch;
	Monster* monster;
	mapOperator* map;
	vector<Monster*> monsterArr;
	Sprite* sprite;
	Knight* hero;
	int bind;

};

#endif // !_SABRE_H_

