/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "SafeMap.h"
#include "SimpleAudioEngine.h"
#include "HeroController.h"
#include "Knight.h"
#include "TMX_Map.h"
#include "ui/CocosGUI.h"
#include "MonsterManager.h"
#include "Monster.h"
#include "sabre.h"
#include "Bullet.h"
#include "FightMap2.h"

USING_NS_CC;
using namespace cocos2d::ui;
using namespace CocosDenshion;


Scene* SafeMap::createScene()
{
	return SafeMap::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in SafeMap.cpp\n");
}

// on "init" you need to initialize your instance
bool SafeMap::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto audio = SimpleAudioEngine::getInstance();
	
	//按钮设置
	auto pauseButton = Button::create("PauseButton.png");
	pauseButton->setAnchorPoint(Vec2(1, 1));
	pauseButton->setPosition(Vec2(1024, 768));
	pauseButton->setScale(0.5);
	addChild(pauseButton, 3);

	auto resumeButton = Button::create("ResumeButton.png");
	resumeButton->setAnchorPoint(Vec2(1, 1));
	resumeButton->setPosition(Vec2(1024, 768));
	resumeButton->setScaleX(0.5);
	resumeButton->setVisible(false);
	addChild(resumeButton, 3);

	auto volumeUpButton = Button::create("Volume+Button.png");
	volumeUpButton->setAnchorPoint(Vec2(1, 1));
	volumeUpButton->setPosition(Vec2(1024, 685));
	volumeUpButton->setScale(0.3);
	addChild(volumeUpButton, 3);

	auto volumeDownButton = Button::create("Volume-Button.png");
	volumeDownButton->setAnchorPoint(Vec2(1, 1));
	volumeDownButton->setPosition(Vec2(1032, 632));
	volumeDownButton->setScale(0.15);
	addChild(volumeDownButton, 3);

	auto exitButton = Button::create("closeButton.png");
	exitButton->setAnchorPoint(Vec2(1, 1));
	exitButton->setPosition(Vec2(100, 100));
	exitButton->setScale(0.8);
	addChild(exitButton, 3);

	pauseButton->addClickEventListener([pauseButton, resumeButton, audio, this](Ref*)
	{
		//游戏暂停
		Director::getInstance()->pause();
		audio->pauseBackgroundMusic();
		pauseButton->setVisible(false);
		resumeButton->setVisible(true);


	});
	resumeButton->addClickEventListener([pauseButton, resumeButton, audio, this](Ref*)
	{
		//游戏继续
		Director::getInstance()->resume();
		audio->resumeBackgroundMusic();
		pauseButton->setVisible(true);
		resumeButton->setVisible(false);


	});
	volumeUpButton->addClickEventListener([audio, this](Ref*)
	{
		audio->setBackgroundMusicVolume(audio->getBackgroundMusicVolume() + 0.1);
	});
	volumeDownButton->addClickEventListener([audio, this](Ref*)
	{
		audio->setBackgroundMusicVolume(audio->getBackgroundMusicVolume() - 0.1);
	});
	exitButton->addClickEventListener([this](Ref*)
	{
		Director::getInstance()->end();
	});

	mapOperator* mapTest = new mapOperator;
	auto Map = TMXTiledMap::create("safeMap/safeMap.tmx");
	mapTest->create(Map);
	addChild(mapTest->returnMap());



	auto controller = HeroController::createHeroController();//添加英雄控制器

	//添加怪物、武器
	auto monster1 = Sprite::create("monsterOne.png");
	monster1->setPosition(195, 640);
	mapTest->returnMap()->addChild(monster1);

	auto monster2 = Sprite::create("monsterThree.png");
	monster2->setPosition(195, 540);
	mapTest->returnMap()->addChild(monster2);

	auto monster3 = Sprite::create("monsterBoss.png");
	monster3->setPosition(195, 440);
	mapTest->returnMap()->addChild(monster3);

	auto monster4 = Sprite::create("monsterTwo.png");
	monster4->setPosition(195, 340);
	mapTest->returnMap()->addChild(monster4);

	auto monster5 = Sprite::create("monsterFour.png");
	monster5->setPosition(195, 240);
	mapTest->returnMap()->addChild(monster5);

	auto rpk = Sprite::create("rpk.png");
	rpk->setPosition(970, 620);
	mapTest->returnMap()->addChild(rpk);

	auto pistol = Sprite::create("pistol.png");
	pistol->setPosition(970, 500);
	mapTest->returnMap()->addChild(pistol);

	auto sabre = Sprite::create("sabre.png");
	sabre->setPosition(965, 380);
	mapTest->returnMap()->addChild(sabre);

	auto wand = Sprite::create("wand.png");
	wand->setPosition(965, 260);
	mapTest->returnMap()->addChild(wand);

	auto scene = Scene::create();
	addChild(scene);
	auto hero = Knight::create();
	hero->setBars(scene, Point(120, 700));
	hero->attacked(-2);
	hero->changeMP(-100);
	hero->schedule(schedule_selector(Hero::updateStatus), 1.0f);


	auto obj = mapTest->getObjPlayer();
	hero->setPosition(obj["x"].asFloat(), obj["y"].asFloat());//通过obj["TypeName"]的形式获取目标属性
	hero->setScale(0.5);//让英雄和一块砖一样大
	hero->setAnchorPoint(Vec2(0.5, 0.5));
	mapTest->addController(controller);
	hero->setTag(1);
	controller->addChild(hero);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(controller->listener, this);





	return true;
}



void SafeMap::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}