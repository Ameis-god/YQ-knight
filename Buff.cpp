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

Buff poisoning(Poisoning, 3.0);
Buff freezing(Freezing, 3.0);
Buff burning(Burning, 3.0);
Buff speedUp(SpeedUp, 3.0);
Buff speedDown(SpeedDown, 3.0);
