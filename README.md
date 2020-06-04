# Soul-knight
use to create the knight game
测试代码实例：
auto k = Knight::create();
	k->setHPBar(this);
	k->setArmorBar(this);
	k->setMPBar(this);
	
	k->attacked(-6);
	k->changeArmor(2);
	k->changeMP(-100);
	
	k->updateHPBar(this);
	k->updateArmorBar(this);
	k->updateMPBar(this);
