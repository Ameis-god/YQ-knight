#include "Boss.h"

bool Boss::init()
{
	HP = 1000;
	limitHP = 1000;
	//myBuff = { speedDown };

	return true;
}

void Boss::attacked(int value)
{
	HP += value;
	updateHPBar();
	if (HP <= 0)
	{
		die();
	}
	
}

void Boss::setBars(Scene *s, Point p)
{
	currentScene = s;

	auto bar = Sprite::create("bossBar.png");
	bar->setPosition(p.x, p.y);
	s->addChild(bar);

	auto sprite = Sprite::create("bossHP.png");
	auto progress = ProgressTimer::create(sprite);
	progress->setType(ProgressTimer::Type::BAR);
	progress->setPosition(p.x, p.y);
	progress->setPercentage(100);
	progress->setName("progressBossHP");
	progress->setMidpoint(Point(0, 0));
	progress->setBarChangeRate(Point(1, 0));
	s->addChild(progress);
}

void Boss::updateHPBar()
{
	auto progress = (ProgressTimer*)currentScene->getChildByName("progressBossHP");

	progress->setPercentage((static_cast<double>(HP) / static_cast<double>(limitHP)) * 100);
}


void Boss::die()
{

}
