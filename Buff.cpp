#include "Buff.h"

Buff::Buff(BuffType buff, int time) 
	:buffType(buff), durations(time) {};

bool Buff::operator ==(const Buff &b)
{
	if (buffType == b.buffType)
	{
		return true;
	}
	return false;
}

Buff poisoning(BuffType::Poisoning, 3.0);
Buff freezing(BuffType::Freezing, 3.0);
Buff burning(BuffType::Burning, 3.0);
Buff speedUp(BuffType::SpeedUp, 1.5);
Buff speedDown(BuffType::SpeedDown, 3.0);
