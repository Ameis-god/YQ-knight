#pragma once
//
//  TMX_Map.hpp
//  MyCppGame-desktop
//
//  Created by 李义尧 on 2020/6/9.
//


#include <stdio.h>
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
using namespace cocos2d;
using namespace CocosDenshion;

class mapOperator : public Node {
public:
    void create(TMXTiledMap* Map);//地图初始化
    TMXTiledMap* returnMap();//获取地图,返回map
    ValueMap getObjPlayer();//从objectGroup获取player
    void addSprite(Sprite* sprite);//将sprite作为节点添加进map
    void addController(Node* controller);
    static void moveMap(MoveBy* move,TMXTiledMap* map);//地图移动,实现视角变化
    void tiledJudgeInit();//道具获取属性初始化
    bool getTiledJudge(int i);//道具拾取判断
    static bool getAndResetTiledJudgeForCreate(int i);//道具获取属性重写
    static bool getAndResetTiledJudgeForPick(int i);
    static bool crashJudge(int x, int y,TMXTiledMap* map);//地图碰撞检测
    static bool boxJudge(int x, int y,TMXTiledMap* map);//宝箱检测
    static bool doorJudge(int x, int y, TMXTiledMap* map);
    static int pickObject(int x, int y,TMXTiledMap* map);
    static void show(int x, int y, TMXTiledMap* map);
    static bool transmissionDoorJudge(int x, int y, TMXTiledMap* map);
    static bool transmissionDoor1Judge(int x, int y,TMXTiledMap* map);//传送门检测,后跟场景切换
    static bool transmissionDoor2Judge(int x, int y, TMXTiledMap* map);
    static void blueMedicineCreate(int x, int y, TMXTiledMap* map);//在地图上创建蓝药
    static void blueMedicineRelease();
    static void redMedicineCreate(int x, int y,TMXTiledMap* map);//在地图上创建红药
    static void redMedicineRelease();
    static void moneyCreate(int x, int y, TMXTiledMap* map);//在地图上创建金币
    static void moneyRelease();
    static void weaponCreate(int x, int y);//在地图上创建武器
    static void weaponRelease();
private:
    TMXTiledMap* map;
    static Sprite* redMedicine;
    static Sprite* blueMedicine;
    static Sprite* money;
    static Sprite* weapon;
    static bool tiledJudgeForCreate[5];//道具创建属性
    static bool tiledJudgeForPick[5];//道具拾取属性
    /*
     我们拾取道具的原理是获取该图块的"identity"等属性判断这里有什么特殊的道具
     但是在程序运行过程中是无法修改图块属性的
     也就是说我们必须想办法让一个图块里的道具只能被获取一次
     所以我设置了一个bool数组用来判断对应道具是否已被获取
     一开始都是true,如果对应道具被获取就变为false
    */
};

