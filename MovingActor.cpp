#include "MovingActor.h"

bool MovingActor::takeBuff(Buff b)
{
	if (myBuff.empty())
	{
		myBuff.push_back(b);
		scheduleOnce(schedule_selector(MovingActor::clearBuff), b.durations);
		return true;
	}

	for (auto it = myBuff.begin(); it != myBuff.end(); it++)
	{
		if ((*it) == b)
		{
			return false;
		}
		//无此buff时进行添加
		else
		{
			myBuff.push_back(b);
			scheduleOnce(schedule_selector(MovingActor::clearBuff), b.durations);
			return true;
		}
	}
	
}

void MovingActor::clearBuff(float dt)
{
	for (int i = 0; i < 5; i++)
	{
		for (auto it = myBuff.begin(); it != myBuff.end(); it++)
		{
			if ((*it).durations <= 0)
			{
				myBuff.erase(it);
				break;
			}
		}
	}
}
