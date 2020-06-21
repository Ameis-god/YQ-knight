#include "Animates.h"

Animate*  Animates::rightRunningAnimate() {
	Vector<SpriteFrame*> frameVec;
	auto frame1 = SpriteFrame::create("Knight_right_standing.png", Rect(0, 0, 100, 100));
	frameVec.pushBack(frame1);
	auto frame2 = SpriteFrame::create("Knight_right_running.png", Rect(0, 0, 100, 100));
	frameVec.pushBack(frame2);
	auto animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(0.1f);
	auto animate = Animate::create(animation);
	return animate;
}
Animate* Animates::leftRunningAnimate() {
	Vector<SpriteFrame*> frameVec;
	auto frame1 = SpriteFrame::create("Knight_left_standing.png", Rect(0, 0, 100, 100));
	frameVec.pushBack(frame1);
	auto frame2 = SpriteFrame::create("Knight_left_running.png", Rect(0, 0, 100, 100));
	frameVec.pushBack(frame2);
	auto animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(0.1f);
	auto animate = Animate::create(animation);
	return animate;

}
Animate* Animates::rightStopAnimate() {
	Vector<SpriteFrame*> frameVec;
	auto frame = SpriteFrame::create("Knight_right_standing.png", Rect(0, 0, 100, 100));
	frameVec.pushBack(frame);
	auto animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(-1);
	auto animate = Animate::create(animation);
	return animate;
}
Animate* Animates::leftStopAnimate() {
	Vector<SpriteFrame*> frameVec;
	auto frame = SpriteFrame::create("Knight_left_standing.png", Rect(0, 0, 100, 100));
	frameVec.pushBack(frame);
	auto animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(-1);
	auto animate = Animate::create(animation);
	return animate;
}

Animate* Animates::rightRunningWithPistolAnimate() {
	Vector<SpriteFrame*> frameVec;
	auto frame1 = SpriteFrame::create("Knight_right_standing_pistol.png", Rect(0, 0, 100, 100));
	frameVec.pushBack(frame1);
	auto frame2 = SpriteFrame::create("Knight_right_running_pistol.png", Rect(0, 0, 100, 100));
	frameVec.pushBack(frame2);
	auto animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(0.1f);
	auto animate = Animate::create(animation);
	return animate;
}
Animate* Animates::leftRunningWithPistolAnimate() {
	Vector<SpriteFrame*> frameVec;
	auto frame1 = SpriteFrame::create("Knight_left_standing_pistol.png", Rect(0, 0, 100, 100));
	frameVec.pushBack(frame1);
	auto frame2 = SpriteFrame::create("Knight_left_running_pistol.png", Rect(0, 0, 100, 100));
	frameVec.pushBack(frame2);
	auto animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(0.1f);
	auto animate = Animate::create(animation);
	return animate;
}
Animate* Animates::rightStopWithPistolAnimate() {
	Vector<SpriteFrame*> frameVec;
	auto frame = SpriteFrame::create("Knight_right_standing_pistol.png", Rect(0, 0, 100, 100));
	frameVec.pushBack(frame);
	auto animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(-1);
	auto animate = Animate::create(animation);
	return animate;
}
Animate* Animates::leftStopWithPistolAnimate() {
	Vector<SpriteFrame*> frameVec;
	auto frame = SpriteFrame::create("Knight_left_standing_pistol.png", Rect(0, 0, 100, 100));
	frameVec.pushBack(frame);
	auto animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(-1);
	auto animate = Animate::create(animation);
	return animate;
}

Animate* Animates::rightRunningWithRpkAnimate() {
	Vector<SpriteFrame*> frameVec;
	auto frame1 = SpriteFrame::create("Knight_right_standing_rpk.png", Rect(0, 0, 100, 100));
	frameVec.pushBack(frame1);
	auto frame2 = SpriteFrame::create("Knight_right_running_rpk.png", Rect(0, 0, 100, 100));
	frameVec.pushBack(frame2);
	auto animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(0.1f);
	auto animate = Animate::create(animation);
	return animate;
}
Animate* Animates::leftRunningWithRpkAnimate() {
	Vector<SpriteFrame*> frameVec;
	auto frame1 = SpriteFrame::create("Knight_left_standing_rpk.png", Rect(0, 0, 100, 100));
	frameVec.pushBack(frame1);
	auto frame2 = SpriteFrame::create("Knight_left_running_rpk.png", Rect(0, 0, 100, 100));
	frameVec.pushBack(frame2);
	auto animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(0.1f);
	auto animate = Animate::create(animation);
	return animate;
}
Animate* Animates::rightStopWithRpkAnimate() {
	Vector<SpriteFrame*> frameVec;
	auto frame = SpriteFrame::create("Knight_right_standing_rpk.png", Rect(0, 0, 100, 100));
	frameVec.pushBack(frame);
	auto animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(-1);
	auto animate = Animate::create(animation);
	return animate;
}
Animate* Animates::leftStopWithRpkAnimate() {
	Vector<SpriteFrame*> frameVec;
	auto frame = SpriteFrame::create("Knight_left_standing_rpk.png", Rect(0, 0, 100, 100));
	frameVec.pushBack(frame);
	auto animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(-1);
	auto animate = Animate::create(animation);
	return animate;
}

Animate* Animates::rightStopWithSabreUpAnimate() {
	Vector<SpriteFrame*> frameVec;
	auto frame = SpriteFrame::create("Knight_right_standing_sabre_up.png", Rect(0, 0, 120, 120));
	frameVec.pushBack(frame);
	auto animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(-1);
	auto animate = Animate::create(animation);
	return animate;
}
Animate* Animates::rightStopWithSabreDownAnimate() {
	Vector<SpriteFrame*> frameVec;
	auto frame = SpriteFrame::create("Knight_right_standing_sabre_down.png", Rect(0, 0, 120, 120));
	frameVec.pushBack(frame);
	auto animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(-1);
	auto animate = Animate::create(animation);
	return animate;
}
Animate* Animates::rightRunningWithSabreAnimate() {
	Vector<SpriteFrame*> frameVec;
	auto frame1 = SpriteFrame::create("Knight_right_standing_sabre_up.png", Rect(0, 0, 120, 120));
	frameVec.pushBack(frame1);
	auto frame2 = SpriteFrame::create("Knight_right_running_sabre.png", Rect(0, 0, 120, 120));
	frameVec.pushBack(frame2);
	auto animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(0.1f);
	auto animate = Animate::create(animation);
	return animate;
}
Animate* Animates::leftStopWithSabreUpAnimate() {
	Vector<SpriteFrame*> frameVec;
	auto frame = SpriteFrame::create("Knight_left_standing_sabre_up.png", Rect(0, 0, 120, 120));
	frameVec.pushBack(frame);
	auto animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(-1);
	auto animate = Animate::create(animation);
	return animate;
}

Animate* Animates::leftStopWithSabreDownAnimate() {
	Vector<SpriteFrame*> frameVec;
	auto frame = SpriteFrame::create("Knight_left_standing_sabre_down.png", Rect(0, 0, 120, 120));
	frameVec.pushBack(frame);
	auto animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(-1);
	auto animate = Animate::create(animation);
	return animate;
}
Animate* Animates::leftRunningWithSabreAnimate() {
	Vector<SpriteFrame*> frameVec;
	auto frame1 = SpriteFrame::create("Knight_left_standing_sabre_up.png", Rect(0, 0, 120, 120));
	frameVec.pushBack(frame1);
	auto frame2 = SpriteFrame::create("Knight_left_running_sabre.png", Rect(0, 0, 120, 120));
	frameVec.pushBack(frame2);
	auto animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(0.1f);
	auto animate = Animate::create(animation);
	return animate;
}

Animate* Animates::rightStopWithWandUpAnimate() {
	Vector<SpriteFrame*> frameVec;
	auto frame = SpriteFrame::create("Knight_right_standing_wand_up.png", Rect(0, 0, 120, 209));
	frameVec.pushBack(frame);
	auto animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(-1);
	auto animate = Animate::create(animation);
	return animate;
}
Animate* Animates::rightStopWithWandDownAnimate() {
	Vector<SpriteFrame*> frameVec;
	auto frame = SpriteFrame::create("Knight_right_standing_wand_down.png", Rect(0, 0, 200, 120));
	frameVec.pushBack(frame);
	auto animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(-1);
	auto animate = Animate::create(animation);
	return animate;
}
Animate* Animates::rightRunningWithWandAnimate() {
	Vector<SpriteFrame*> frameVec;
	auto frame1 = SpriteFrame::create("Knight_right_standing_wand_up.png", Rect(0, 0, 120, 209));
	frameVec.pushBack(frame1);
	auto frame2 = SpriteFrame::create("Knight_right_running_wand.png", Rect(0, 0, 120, 209));
	frameVec.pushBack(frame2);
	auto animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(0.1f);
	auto animate = Animate::create(animation);
	return animate;
}
Animate* Animates::leftStopWithWandUpAnimate() {
	Vector<SpriteFrame*> frameVec;
	auto frame = SpriteFrame::create("Knight_left_standing_wand_up.png", Rect(0, 0, 120, 209));
	frameVec.pushBack(frame);
	auto animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(-1);
	auto animate = Animate::create(animation);
	return animate;
}

Animate* Animates::leftStopWithWandDownAnimate() {
	Vector<SpriteFrame*> frameVec;
	auto frame = SpriteFrame::create("Knight_left_standing_wand_down.png", Rect(0, 0, 200, 120));
	frameVec.pushBack(frame);
	auto animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(-1);
	auto animate = Animate::create(animation);
	return animate;
}
Animate* Animates::leftRunningWithWandAnimate() {
	Vector<SpriteFrame*> frameVec;
	auto frame1 = SpriteFrame::create("Knight_left_standing_wand_up.png", Rect(0, 0, 120, 209));
	frameVec.pushBack(frame1);
	auto frame2 = SpriteFrame::create("Knight_left_running_wand.png", Rect(0, 0, 120, 209));
	frameVec.pushBack(frame2);
	auto animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(0.1f);
	auto animate = Animate::create(animation);
	return animate;
}
