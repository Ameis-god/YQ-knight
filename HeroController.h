#pragma once
#include "cocos2d.h"
#include "Knight.h"
#include "TMX_Map.h"
#include "Animates.h"
#include "SimpleAudioEngine.h"
#include "sabre.h"
#include "MonsterManager.h"
#include "FightMap2.h"
#include "HelloWorldScene.h"
#include "Bullet.h"
#include "SafeMap.h"
#include<time.h>
USING_NS_CC;

class HeroController :public Node
{
public:
	//用于创建控制器的函数
	static HeroController* createHeroController();

	//初始化控制器的函数
	void heroControllerInit();

	CREATE_FUNC(HeroController);



	//获取私有变量keys的函数
	std::map<cocos2d::EventKeyboard::KeyCode, bool> getKeys();

	//获取私有变量direction的函数
	int getDirection();

	//改变私有变量direction的函数
	void setDirection(int direction);



	//按下按键瞬间和放开按键瞬间调用的函数，以后可以增加射击按键等
	virtual void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	virtual void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);

	//启动英雄跑动动画的函数，在按下WASD键的瞬间调用
	void startRunningAnimation(cocos2d::EventKeyboard::KeyCode keyCode);

	//停止英雄跑动动画的函数，在释放WASD键的瞬间调用
	void stopRunningAnimation(cocos2d::EventKeyboard::KeyCode keyCode);

	void startAttackAnimation();
	void stopAttackAnimation();

	void switchWeapon(EventKeyboard::KeyCode keyCode);

	//update函数,由自带的scheduleUpdate函数调用，每一帧调用一次
	void update(float dt);

	//判断某个键是否正在被按下的函数
	bool isKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode);

	//WASD键被按下过程中会调用的函数，实现英雄的移动，两个重载函数分别对应按下一个键(上下左右移动)和按下两个键(斜45度移动)
	void keyPressedDuration(cocos2d::EventKeyboard::KeyCode keyCode, float speed);
	void keyPressedDuration(cocos2d::EventKeyboard::KeyCode keyCode1, cocos2d::EventKeyboard::KeyCode keyCode2, float speed);

	//键盘事件侦听器
	EventListenerKeyboard* listener;



private:
	//用来保存按键记录（按哪个键、是否正在被按下）
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;

	//用于判断英雄的图像当前朝左还是朝右，1代表朝右，2代表朝左(开始时默认朝右)
	int direction = 1;

};