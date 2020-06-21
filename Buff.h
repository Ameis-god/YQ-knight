#ifndef __BUFF_H__
#define __BUFF_H__

#include<iostream>

enum class BuffType
{
	Poisoning,//中毒
	Freezing,//冰冻
	Burning,//烧伤
	SpeedUp,//加速
	SpeedDown,//减速
};

class Buff
{
public:
	BuffType buffType;//buff类型
	float durations;//持续时间

	Buff(BuffType buff, int time);
	//~Buff();
	bool operator ==(const Buff &b);
};

extern Buff poisoning;
extern Buff freezing;
extern Buff burning;
extern Buff speedUp;
extern Buff speedDown;



#endif // !__BUFF_H__

