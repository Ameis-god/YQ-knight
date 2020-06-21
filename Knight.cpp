#include "Knight.h"

bool Knight::init()
{
	HP = 6;
	limitHP = 6;
	armor = 4;
	limitArmor = 4;
	MP = 200;
	limitMP = 200;
	gold = 0;
	skillCooldownTime = 10.0f;
	skillLastTime = 6.0f;
	movingSpeed = 6.0f;

	initWithFile("Knight_right_standing_pistol.png", Rect(0, 0, 100, 100));

	underAttacked = false;
	underSkill = false;
	lastAttackedTime = 0;
	lastOpenSkill = -10000;
	currentTime = 0;



	return true;
}