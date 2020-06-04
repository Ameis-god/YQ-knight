#include "example.h"

bool Knight::init()
{
	HP = 6;
	limitHP = 6;
	armor = 4;
	limitArmor = 4;
	MP = 200;
	limitMP = 200;
		
	return true;

}
		
int Knight::getHP()
{
	return HP;
}

int Knight::getLimitHP()
{
	return limitHP;
}

void Knight::changeHP(int value)
{
	if (value > 0)
	{
		/*加血效果动画*/

		HP = ((HP + value) > limitHP) ? limitHP : (HP + value);
	}
	else
	{
		/*扣血效果动画*/

		HP += value;
		if (HP <= 0)
		{
			die();
		}
	}
}

void Knight::setHPBar(Scene *s)
{
	//获取当前界面大小
	auto visibleSize = Director::getInstance()->getVisibleSize();
	
	//设置血条底层
	auto spriteBar = Sprite::create("bar.png");
	spriteBar->setPosition(visibleSize.width / 2, visibleSize.height - 20);
	s->addChild(spriteBar);

	//设置血条上层
	auto spriteHP = Sprite::create("HP.png");
	auto progressHP = ProgressTimer::create(spriteHP);
	progressHP->setType(ProgressTimer::Type::BAR);
	progressHP->setPosition(visibleSize.width / 2, visibleSize.height - 20);
	progressHP->setPercentage(100);

	progressHP->setName("progressHP");//设置名字
	progressHP->setMidpoint(Point(0, 0));
	progressHP->setBarChangeRate(Point(1, 0));
	s->addChild(progressHP);

	//设置显示数值
	auto labelHP = Label::createWithSystemFont("00", "Arial", 20);
	//HPLabel->setColor(Color3B::BLACK);
	labelHP->setName("labelHP");
	labelHP->setPosition(visibleSize.width / 2, visibleSize.height - 20);
	s->addChild(labelHP);
}

void Knight::updateHPBar(Scene *s)
{
	auto progress = (ProgressTimer*)s->getChildByName("progressHP");
	progress->setPercentage((static_cast<double>(HP)/static_cast<double>(limitHP))* 100);

	auto label = (Label*)s->getChildByName("labelHP");
	label->setString(StringUtils::format("%d/%d", HP, limitHP));
}

int Knight::getArmor()
{
	return armor;
}
int Knight::getLimitArmor()
{
	return limitArmor;
}
void Knight::changeArmor(int value)
{
	armor += value;
}

void Knight::setArmorBar(Scene *s)
{
	//获取当前界面大小
	auto visibleSize = Director::getInstance()->getVisibleSize();

	//设置护甲条底层
	auto spriteBar = Sprite::create("bar.png");
	spriteBar->setPosition(visibleSize.width / 2, visibleSize.height - 50);
	s->addChild(spriteBar);

	//设置护甲条上层
	auto spriteArmor = Sprite::create("armor.png");
	auto progressArmor = ProgressTimer::create(spriteArmor);
	progressArmor->setType(ProgressTimer::Type::BAR);
	progressArmor->setPosition(visibleSize.width / 2, visibleSize.height - 50);
	progressArmor->setPercentage(100);

	progressArmor->setName("progressArmor");//设置名字
	progressArmor->setMidpoint(Point(0, 0));
	progressArmor->setBarChangeRate(Point(1, 0));
	s->addChild(progressArmor);

	//设置显示数值
	auto labelArmor = Label::createWithSystemFont("00", "Arial", 20);
	//HPLabel->setColor(Color3B::BLACK);
	labelArmor->setName("labelArmor");
	labelArmor->setPosition(visibleSize.width / 2, visibleSize.height - 50);
	s->addChild(labelArmor);
}

void Knight::updateArmorBar(Scene *s)
{
	auto progress = (ProgressTimer*)s->getChildByName("progressArmor");
	progress->setPercentage((static_cast<double>(armor) / static_cast<double>(limitArmor)) * 100);

	auto label = (Label*)s->getChildByName("labelArmor");
	label->setString(StringUtils::format("%d/%d", armor, limitArmor));
}

void Knight::attacked(int value)
{
	/*受攻击动画*/
	changeArmor(value);
	if (armor < 0)
	{
		changeHP(armor);
		armor = 0;
	}
}

int Knight::getMP() { return MP; }
int Knight::getLimitMP() { return limitMP; }
void Knight::changeMP(int value)
{
	if (value > 0)
	{
		/*加法动画*/
		MP = ((MP + value) > limitMP) ? limitMP : (MP + value);
	}
	else
	{
		MP += value;
		if (MP < 0)
		{
			/*法力值不足提示*/
			MP -= value;
		}
	}
}

void Knight::setMPBar(Scene *s)
{
	//获取当前界面大小
	auto visibleSize = Director::getInstance()->getVisibleSize();

	//设置魔力条底层
	auto spriteBar = Sprite::create("bar.png");
	spriteBar->setPosition(visibleSize.width / 2, visibleSize.height - 80);
	s->addChild(spriteBar);

	//设置魔力条上层
	auto spriteMP = Sprite::create("MP.png");
	auto progressMP = ProgressTimer::create(spriteMP);
	progressMP->setType(ProgressTimer::Type::BAR);
	progressMP->setPosition(visibleSize.width / 2, visibleSize.height - 80);
	progressMP->setPercentage(100);

	progressMP->setName("progressMP");//设置名字
	progressMP->setMidpoint(Point(0, 0));
	progressMP->setBarChangeRate(Point(1, 0));
	s->addChild(progressMP);

	//设置显示数值
	auto labelMP = Label::createWithSystemFont("00", "Arial", 20);
	//HPLabel->setColor(Color3B::BLACK);
	labelMP->setName("labelMP");
	labelMP->setPosition(visibleSize.width / 2, visibleSize.height - 80);
	s->addChild(labelMP);
}

void Knight::updateMPBar(Scene *s)
{
	auto progress = (ProgressTimer*)s->getChildByName("progressMP");
	progress->setPercentage((static_cast<double>(MP) / static_cast<double>(limitMP)) * 100);

	auto label = (Label*)s->getChildByName("labelMP");
	label->setString(StringUtils::format("%d/%d", MP, limitMP));
}



void Knight::die()
{
	log("GG");
	/*游戏结束动画*/
}
