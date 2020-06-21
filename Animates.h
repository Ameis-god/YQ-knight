#pragma once
#include "cocos2d.h"
USING_NS_CC;
class Animates {
public:
	static Animate* rightRunningAnimate();
	static Animate* leftRunningAnimate();
	static Animate* rightStopAnimate();
	static Animate* leftStopAnimate();

	static Animate* rightRunningWithPistolAnimate();
	static Animate* leftRunningWithPistolAnimate();
	static Animate* rightStopWithPistolAnimate();
	static Animate* leftStopWithPistolAnimate();

	static Animate* rightRunningWithRpkAnimate();
	static Animate* leftRunningWithRpkAnimate();
	static Animate* rightStopWithRpkAnimate();
	static Animate* leftStopWithRpkAnimate();

	
	static Animate* rightStopWithSabreUpAnimate();
	static Animate* rightStopWithSabreDownAnimate();
	static Animate* rightRunningWithSabreAnimate();
	static Animate* leftStopWithSabreUpAnimate();
	static Animate* leftStopWithSabreDownAnimate();
	static Animate* leftRunningWithSabreAnimate();

	static Animate* rightStopWithWandUpAnimate();
	static Animate* rightStopWithWandDownAnimate();
	static Animate* rightRunningWithWandAnimate();
	static Animate* leftStopWithWandUpAnimate();
	static Animate* leftStopWithWandDownAnimate();
	static Animate* leftRunningWithWandAnimate();
};