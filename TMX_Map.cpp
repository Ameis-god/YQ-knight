#include "TMX_Map.h"

Sprite* mapOperator::redMedicine = new Sprite;
Sprite* mapOperator::blueMedicine = new Sprite;
Sprite* mapOperator::money = new Sprite;
bool mapOperator::tiledJudgeForCreate[5] = { false };
bool mapOperator::tiledJudgeForPick[5] = { false };

void mapOperator::create(TMXTiledMap* Map) {
    mapOperator::map = Map;//加载地图
    mapOperator::map->setAnchorPoint(Vec2(0, 0));
    mapOperator::map->setPosition(0, 0);//将地图左下角与显示界面左下角对齐
    mapOperator::tiledJudgeInit();//道具获取属性初始化
}

TMXTiledMap* mapOperator::returnMap() {
    return map;//获取地图
}

bool mapOperator::crashJudge(int x, int y,TMXTiledMap* map) {
    auto judgeLayer = map->getLayer("judgeLayer");
    /*
     获取judgeLayer层
     现在所有的属性都通过judgeLayer层获取
     */
    auto gid = judgeLayer->getTileGIDAt(Vec2(x, y));
    //根据传进来的(x,y)获取目标图块gid值
    auto property = map->getPropertiesForGID(gid).asValueMap();
    //根据gid值获取属性组
    return property["move"].asBool();//返回一个bool值,true则执行移动,false则不执行移动
}

bool mapOperator::boxJudge(int x, int y,TMXTiledMap* map) {
    auto judgeLayer = map->getLayer("judgeLayer");
    auto gid = judgeLayer->getTileGIDAt(Vec2(x, y));
    auto property = map->getPropertiesForGID(gid).asValueMap();
    //和上面一样都是获取属性
    if (property["identity"].asString() == "box") {
        auto sprite = judgeLayer->getTileAt(Vec2(x, y));//将该图块获取为一个精灵
        auto openBox = Sprite::create("openBox.png");//利用获取到的精灵的坐标初始化另一个精灵,将其设置为打开的宝箱的样子,从而实现开宝箱
        openBox->setPosition(sprite->getPosition().x + 16, sprite->getPosition().y + 14);//+8,+7是为了对齐,让打开的宝箱刚好覆盖原宝箱,在不同的pc运行可能有差别
        map->addChild(openBox, 0);
        /*
         打开的宝箱添加进map里,我需要解释一下第二个参数
         第二个参数0代表"绘制"顺序,设置为0是为了让它显示在地板之上,人物之下,即不会遮挡人物
         至于为什么设置为0请联系我
         */
        if (property["content"].asString() == "redMedicine" && mapOperator::getAndResetTiledJudgeForCreate(0)) {
            /*/
             如果该图块的"medicineType"属性为"redMedicine"且其在tiledJudge里对应值为true(为了避免一个道具被多次获取),就创建红药
             */
            mapOperator::redMedicineCreate(sprite->getPosition().x + 18, sprite->getPosition().y + 16,map);//这里涉及坐标调整,为了更好地显示
            log("red medicine got");            //输出日志测试一下红药已被识别,正常情况下只会识别到一次
            //redMedicine->setVisible(false);//红药设置为不可见

        }
        if (property["content"].asString() == "blueMedicine" && mapOperator::getAndResetTiledJudgeForCreate(1)) {
            /*/
             如果该图块的"medicineType"属性为"redMedicine"且其在tiledJudge里对应值为true(为了避免一个道具被多次获取),就创建红药
             */
            mapOperator::blueMedicineCreate(sprite->getPosition().x + 18, sprite->getPosition().y + 16, map);//这里涉及坐标调整,为了更好地显示
            log("red medicine got");            //输出日志测试一下红药已被识别,正常情况下只会识别到一次
            //redMedicine->setVisible(false);//红药设置为不可见

        }
        if (property["content"].asString() == "money" && mapOperator::getAndResetTiledJudgeForCreate(2)) {
            /*/
             如果该图块的"medicineType"属性为"redMedicine"且其在tiledJudge里对应值为true(为了避免一个道具被多次获取),就创建红药
             */
            mapOperator::moneyCreate(sprite->getPosition().x + 18, sprite->getPosition().y + 16, map);//这里涉及坐标调整,为了更好地显示
            log("red medicine got");            //输出日志测试一下红药已被识别,正常情况下只会识别到一次
            //redMedicine->setVisible(false);//红药设置为不可见

        }
        return true;
    }
    else return false;
}

bool mapOperator::doorJudge(int x, int y, TMXTiledMap* map) {
    auto judgeLayer = map->getLayer("judgeLayer");
    auto gid = judgeLayer->getTileGIDAt(Vec2(x, y));
    auto property = map->getPropertiesForGID(gid).asValueMap();
    log("%s", property["move"].asString().c_str());//测试一下获取的属性
    if (property["identity"].asString() == "door") {
        return true;
    }
    else return false;
    //return property["move"].asBool();//返回一个bool值,true则执行移动,false则不执行移动
}

int mapOperator::pickObject(int x, int y,TMXTiledMap* map) {

    auto judgeLayer = map->getLayer("judgeLayer");
    auto gid = judgeLayer->getTileGIDAt(Vec2(x, y));
    auto property = map->getPropertiesForGID(gid).asValueMap();
    log("%s", property["content"].asString().c_str());
    if (property["content"].asString() == "redMedicine" && getAndResetTiledJudgeForPick(0) && !getAndResetTiledJudgeForCreate(0)) {
        log("red medicine got");
        mapOperator::redMedicineRelease();
        auto effect = SimpleAudioEngine::getInstance();
        effect->playEffect("Pick.mp3");
        return 0;
    }
    else if (property["content"].asString() == "blueMedicine" && getAndResetTiledJudgeForPick(1) && !getAndResetTiledJudgeForCreate(1)) {
        log("blue medicine got");
        mapOperator::blueMedicineRelease();
        auto effect = SimpleAudioEngine::getInstance();
        effect->playEffect("Pick.mp3");
        return 1;
    }
    else if (property["content"].asString() == "money" && getAndResetTiledJudgeForPick(2) && !getAndResetTiledJudgeForCreate(2)) {
        log("money got");
        mapOperator::moneyRelease();
        auto effect = SimpleAudioEngine::getInstance();
        effect->playEffect("Pick.mp3");
        return 2;
    }
    else if (property["content"].asString() == "weapon" && getAndResetTiledJudgeForPick(3) && getAndResetTiledJudgeForCreate(3)) {
        log("weapon got");
        mapOperator::blueMedicineRelease();
        auto effect = SimpleAudioEngine::getInstance();
        effect->playEffect("Pick.mp3");
        return 3;
    }
    else return 4;
}

void mapOperator::show(int x, int y,TMXTiledMap* map) {
    auto judgeLayer = map->getLayer("judgeLayer");
    auto gid = judgeLayer->getTileGIDAt(Vec2(x, y));
    auto property = map->getPropertiesForGID(gid).asValueMap();
    log("%s", property["move"].asString().c_str());//测试一下获取的属性
    if (property["identity"].asString() == "show") {//判断当前图块是否为展示区
        auto title = property["name"].asString();//获取标题
        auto message = property["character"].asString();//获取介绍内容
        MessageBox(title.c_str(), message.c_str());//通过messageBox输出
    }
}

void mapOperator::redMedicineCreate(int x, int y,TMXTiledMap* map) {
    redMedicine = Sprite::create("redMedicine.png");
    redMedicine->setPosition(x, y);
    map->addChild(redMedicine, 1);
}

void mapOperator::blueMedicineCreate(int x, int y, TMXTiledMap* map) {
   blueMedicine = Sprite::create("blueMedicine.png");
    blueMedicine->setPosition(x, y);
    map->addChild(blueMedicine, 1);
}
void mapOperator::moneyCreate(int x, int y, TMXTiledMap* map) {
    redMedicine = Sprite::create("money.png");
    redMedicine->setPosition(x, y);
    map->addChild(money, 1);
}

void mapOperator::redMedicineRelease() {
    redMedicine->setVisible(false);
}

void mapOperator::blueMedicineRelease() {
    blueMedicine->setVisible(false);
}
void mapOperator::moneyRelease() {
    money->setVisible(false);
}

bool mapOperator::transmissionDoorJudge(int x, int y, TMXTiledMap* map) {//传送门识别,用来从一张地图到另一张地图,原理都一样,还没具体实现
    auto judgeLayer = map->getLayer("judgeLayer");
    auto gid = judgeLayer->getTileGIDAt(Vec2(x, y));
    auto property = map->getPropertiesForGID(gid).asValueMap();
    if (property["identity"].asString() == "transmissionDoor") {
        return true;
    }
    else return false;
}

bool mapOperator::transmissionDoor1Judge(int x, int y,TMXTiledMap* map) {//传送门识别,用来从一张地图到另一张地图,原理都一样,还没具体实现
    auto judgeLayer = map->getLayer("judgeLayer");
    auto gid = judgeLayer->getTileGIDAt(Vec2(x, y));
    auto property = map->getPropertiesForGID(gid).asValueMap();
    if (property["identity"].asString() == "transmissionDoor2") {
        return true;
    }
    else return false;
}

bool mapOperator::transmissionDoor2Judge(int x, int y, TMXTiledMap* map) {//传送门识别,用来从一张地图到另一张地图,原理都一样,还没具体实现
    auto judgeLayer = map->getLayer("judgeLayer");
    auto gid = judgeLayer->getTileGIDAt(Vec2(x, y));
    auto property = map->getPropertiesForGID(gid).asValueMap();
    if (property["identity"].asString() == "transmissionDoor3") {
        return true;
    }
    else return false;
}

ValueMap mapOperator::getObjPlayer() {
    auto objectGroup = map->getObjectGroup("objectLayer");//获取对象层
    return objectGroup->getObject("player");//从对象层获取player
}

void mapOperator::addSprite(Sprite* sprite) {
    map->addChild(sprite, 2);//将精灵添加到地图,这里的渲染顺序是1,意味着它会遮盖渲染顺序是0的对象,我们前面介绍过
}

void mapOperator::moveMap(MoveBy* move,TMXTiledMap* map) {
    map->runAction(move);//地图移动
}

void mapOperator::tiledJudgeInit() {
    for (int i = 0; i < 5; i++) {
        tiledJudgeForPick[i] = true;//地图获取属性初始化
        tiledJudgeForCreate[i] = true;
    }
}
bool mapOperator::getAndResetTiledJudgeForCreate(int i) {
    if (tiledJudgeForCreate[i] == true) {//如果对应值为true代表这个道具还没有被获取过
        tiledJudgeForCreate[i] = false;//将属性修改为false,代表我们已经获取过这个属性了
        return true;
    }
    else return false;
}

bool mapOperator::getAndResetTiledJudgeForPick(int i) {
    if (tiledJudgeForPick[i] == true) {//如果对应值为true代表这个道具还没有被获取过
        tiledJudgeForPick[i] = false;//将属性修改为false,代表我们已经获取过这个属性了
        return true;
    }
    else return false;
}

void mapOperator::addController(Node* controller) {
    map->addChild(controller, 2);
}