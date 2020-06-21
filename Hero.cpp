#include<string>
#include "MovingActor.h"
#include "Hero.h"

//设置属性条
void Hero::setBars(Scene* s, const Point p)
{
	currentScene = s;

	//以下为设置位于左上方的属性条
	auto background = Sprite::create("Board.png");
	background->setPosition(p.x, p.y);
	s->addChild(background);
	for (int i = 0; i < 3; i++)
	{
		//设置底层
		auto bar = Sprite::create("bar.png");

		bar->setPosition(p.x + 20, p.y - (i - 1) * 25);
		s->addChild(bar);

		//设置上层
		std::string filename;//创建的图片名
		std::string progressName;
		std::string labelName;
		switch (i)
		{
		case 0:
			filename = "HP.png";
			progressName = "progressHP";
			labelName = "labelHP";
			break;
		case 1:
			filename = "armor.png";
			progressName = "progressArmor";
			labelName = "labelArmor";
			break;
		case 2:
			filename = "MP.png";
			progressName = "progressMP";
			labelName = "labelMP";
			break;
		}

		auto sprite = Sprite::create(filename);
		auto progress = ProgressTimer::create(sprite);
		progress->setType(ProgressTimer::Type::BAR);
		progress->setPosition(p.x + 20, p.y - (i - 1) * 25);
		progress->setPercentage(100);

		progress->setName(progressName);
		progress->setMidpoint(Point(0, 0));
		progress->setBarChangeRate(Point(1, 0));
		s->addChild(progress);

		//设置显示数值
		auto label = Label::createWithSystemFont("00", "Arial", 18);
		label->setName(labelName);
		label->setPosition(p.x + 20, p.y - (i - 1) * 25);
		s->addChild(label);
	}
	updateHPBar();
	updateArmorBar();
	updateMPBar();
}

//设置金币
void Hero::setGold(Scene* s, const Point p)
{
	//设置金币图标
	auto gold = Sprite::create("money.png");
	gold->setPosition(p.x, p.y);
	s->addChild(gold);

	auto label = Label::createWithSystemFont("0", "Arial", 18);
	label->setName("labelGold");
	label->setColor(Color3B::YELLOW);
	label->setPosition(p.x + 50, p.y);
	s->addChild(label);
}

//设置技能图标
void Hero::setSkillIcon(Scene* s, const Point p)
{
	currentScene = s;
	auto sprite = Sprite::create("knightSkill.png");
	auto progress = ProgressTimer::create(sprite);
	progress->setType(ProgressTimer::Type::RADIAL);
	progress->setPosition(p.x, p.y);
	progress->setPercentage(100);
	progress->setName("progressSkill");

	s->addChild(progress);
	//uodateSkillIcon();
}

//更新血条
void Hero::updateHPBar()
{
	auto progress = (ProgressTimer*)currentScene->getChildByName("progressHP");

	progress->setPercentage((static_cast<double>(HP) / static_cast<double>(limitHP)) * 100);

	auto label = (Label*)currentScene->getChildByName("labelHP");
	label->setString(StringUtils::format("%d/%d", HP, limitHP));
}

//改变血量
void Hero::changeHP(const int value)
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
	updateHPBar();
}

//改变血量上限
void Hero::changeLimitHP(const int value)
{
	if (value > 0)
	{
		limitHP += value;
		HP += value;
	}
	else
	{
		limitHP += value;
		if (HP > limitHP)
		{
			HP = limitHP;
		}
	}
	updateHPBar();
}

//更新护甲条
void Hero::updateArmorBar()
{
	auto progress = (ProgressTimer*)currentScene->getChildByName("progressArmor");
	progress->setPercentage((static_cast<double>(armor) / static_cast<double>(limitArmor)) * 100);

	auto label = (Label*)currentScene->getChildByName("labelArmor");
	label->setString(StringUtils::format("%d/%d", armor, limitArmor));
}

//改变护甲值
void Hero::changeArmor(const int value)
{
	if (value < 0)
	{
		armor += value;
	}
	else if (armor < limitArmor)
	{
		armor += value;
	}
	updateArmorBar();
}

//改变护甲上限
void Hero::changeLimitArmor(const int value)
{
	limitArmor += value;
	armor += value;
	updateArmorBar();
}

//更新蓝条
void Hero::updateMPBar()
{
	auto progress = (ProgressTimer*)currentScene->getChildByName("progressMP");
	progress->setPercentage((static_cast<double>(MP) / static_cast<double>(limitMP)) * 100);

	auto label = (Label*)currentScene->getChildByName("labelMP");
	label->setString(StringUtils::format("%d/%d", MP, limitMP));
}

//改变蓝量
void Hero::changeMP(const int value)
{
	if (value > 0)
	{
		/*回蓝动画*/
		MP = ((MP + value) > limitMP) ? limitMP : (MP + value);
	}
	else
	{
		if (!underSkill)
		{
			MP += value;
			if (MP < 0)
			{
				MP -= value;
			}
		}
	}
	updateMPBar();
}

//改变蓝量上限
void Hero::changeLimitMP(const int value)
{
	limitMP += value;
	MP += value;
	updateMPBar();
}

//更新金币值
void Hero::updateGold()
{
	auto label = (Label*)currentScene->getChildByName("labelGold");
	label->setString(StringUtils::format("%d", gold));
}

//改变金币
void Hero::changeGold(const int value)
{
	if (value > 0)
	{
		gold += value;
	}
	else
	{
		if (gold + value >= 0)
		{
			gold += value;
		}
		else
		{
			/*无法购买*/
		}
	}
	updateGold();
}

//收到伤害
void Hero::attacked(const int value)
{
	lastAttackedTime = clock();
	//log("%d", lastAttackedTime);
	underAttacked = true;
	/*受攻击动画*/
	if (!underSkill)
	{
		changeArmor(value);
		if (armor < 0)
		{
			changeHP(armor);
			armor = 0;
		}
		updateArmorBar();
	}
}

//更新技能图标
void Hero::updateSkillIcon(float dt)
{
	auto progress = (ProgressTimer*)currentScene->getChildByName("progressSkill");

	progress->setPercentage(progress->getPercentage() + 1);

	if (progress->getPercentage() >= 100)
	{
		unschedule(schedule_selector(Hero::updateSkillIcon));
	}
}

//开启技能
bool Hero::openSkill()
{
	currentTime = clock();
	//log("%d", currentTime - lastOpenSkill);
	if (currentTime - lastOpenSkill < 1000 * skillCooldownTime)
	{
		//log("?");
		return false;
	}
	else
	{
		//log("!");
		//修改状态
		underSkill = true;
		takeBuff(speedUp);
		scheduleOnce(schedule_selector(Hero::closeSkill), skillLastTime);

		return true;
	}
}

//关闭技能
void Hero::closeSkill(float dt)
{
	lastOpenSkill = clock();
	underSkill = false;
	movingSpeed = 6;
	auto progress = (ProgressTimer*)currentScene->getChildByName("progressSkill");
	progress->setPercentage(0);
	schedule(schedule_selector(Hero::updateSkillIcon), skillCooldownTime / 100);
}

//更新状态
void Hero::updateStatus(float dt)
{
	//护甲恢复机制
	currentTime = clock();
	if (currentTime - lastAttackedTime >= 3000)
	{
		underAttacked = false;
	}
	if (!underAttacked)
	{
		changeArmor(1);
	}
	//相应buff
	for (auto it = myBuff.begin(); it != myBuff.end(); it++)
	{
		switch ((*it).buffType)
		{
		case BuffType::Poisoning:
		{
			/*中毒效果*/
			(*it).durations--;
			attacked(-1);
			break;
		}
		case BuffType::Freezing:
		{
			//冰冻效果
			(*it).durations--;
			break;
		}
		case BuffType::Burning:
		{
			//烧伤效果
			(*it).durations--;
			attacked(-1);
			break;
		}
		case BuffType::SpeedUp:
		{
			//加速效果
			(*it).durations--;
			movingSpeed = 9;
			break;
		}
		case BuffType::SpeedDown:
		{
			//减速效果
			(*it).durations--;
			movingSpeed *= 0.75;
			break;
		}
		}
	}


}

int Hero::getMP() {
	return MP;
}

void Hero::setWeaponNum(int weaponnum) {
	weaponNum = weaponnum;
}

int Hero::getWeaponNum() {
	return weaponNum;
}

void Hero::die()
{
	Director::getInstance()->replaceScene(TransitionFade::create(1.5, SafeMap::createScene()));
}