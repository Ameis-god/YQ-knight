#include"sabre.h"
#include"cocos2d.h"
//using namespace cocos2d;


void Sabre::sabreinit(MonsterManager* monsterOne, Knight* knight, mapOperator* mapO) {
	bindMonster(monsterOne);
	bindHero(knight);
	bindMonster(mapO);
}
void Sabre::bindMonster(mapOperator* mapO) {
	map = mapO;
}
void Sabre::isLanched(int n) {
	if (n == 1) {
		if (aimMon() == 1) {
			monster->hit();
			monster->attacked(-1);
			monster->hide(monster, hero, map, bind);
		}
	}
	else if (n == 2) {
		if (aimMon() == 1) {
			monster->hit();
			monster->attacked(-2);
			monster->hide(monster, hero, map, bind);
			hero->changeMP(-2);
		}
	}
}
int Sabre::aimMon() {
	for (int i = 0; i < monsterArr.size(); i++) {

		if (monsterArr[i]->getBoundingBox().containsPoint(Point(hero->getPosition().x - 20, hero->getPosition().y - 20)) || monsterArr[i]->getBoundingBox().containsPoint(Point(hero->getPosition().x, hero->getPosition().y)) || monsterArr[i]->getBoundingBox().containsPoint(Point(hero->getPosition().x - 50, hero->getPosition().y))) {
			monster = monsterArr[i];
			bind = i;
			return 1;

		}
	}
	return 0;
}
void Sabre::bindMonster(MonsterManager* monsterOne) {
	monsterArr = monsterOne->bindMArr();
}
void Sabre::bindSprite() {

}
void Sabre::update(float dt) {

}
void Sabre::switchSabre() {

}
int Sabre::iAttacked() {
	return 1;
}
void Sabre::bindHero(Knight* knight) {
	hero = knight;
}

