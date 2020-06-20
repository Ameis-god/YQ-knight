#include "Monster.h"

//怪物死亡
void Monster::die()
{
	//可放置出现金币等
}

//受到伤害
void Monster::attacked(int value)
{
	HP += value;
	if (HP <= 0)
	{
		die();
	}
}

//更新状态
void Monster::updateStatus(float dt)
{
	for (auto it = myBuff.begin(); it != myBuff.end(); it++)
	{
		switch ((*it).buffType)
		{
		case Poisoning:
		{
			/*中毒效果*/
			(*it).durations--;
			attacked(-30);
			break;
		}
		case Freezing:
		{
			//冰冻效果
			(*it).durations--;
			break;
		}
		case Burning:
		{
			//烧伤效果
			(*it).durations--;
			attacked(-3);
			break;
		}
		case SpeedUp:
		{
			//加速效果
			(*it).durations--;
			movingSpeed *= 1.5;
			break;
		}
		case SpeedDown:
		{
			//减速效果
			(*it).durations--;
			movingSpeed *= 0.75;
			break;
		}
		}
	}
}

//初始化近战怪物
bool MeleeMonster::init()
{
	HP = 15;
	AD = 2;
	movingSpeed = 100;

	return true;
}
