#include "StartScene.h"
#include "SimpleAudioEngine.h"
#include "SafeMap.h"

USING_NS_CC;
using namespace CocosDenshion;

Scene* StartScene::createScene()
{
    return StartScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool StartScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto audio = SimpleAudioEngine::getInstance();
    audio->playBackgroundMusic("Forest.mp3", true);
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto startItem = MenuItemImage::create(
        "StartButton.png",
        "StartButton.png",
        CC_CALLBACK_1(StartScene::menuStartCallback, this));

    if (startItem == nullptr ||
        startItem->getContentSize().width <= 0 ||
        startItem->getContentSize().height <= 0)
    {
        problemLoading("'StartButton.png' and 'StartButton.png'");
    }
    else
    {
        float x = visibleSize.width / 2;
        float y = visibleSize.height / 2;
        startItem->setPosition(Vec2(x, y));
    }

    auto closeItem = MenuItemImage::create(
        "CloseButton.png",
        "CloseButton.png",
        CC_CALLBACK_1(StartScene::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseButton.png' and 'CloseButton.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
        float y = origin.y + closeItem->getContentSize().height / 2;
        closeItem->setPosition(Vec2(x, y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(startItem, closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...


    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("StartScene.png");
    if (sprite == nullptr)
    {
        problemLoading("'StartScene.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }
    return true;
}

void StartScene::menuStartCallback(Ref* pSender)
{
    auto nextScene = SafeMap::createScene();
    Director::getInstance()->pushScene(nextScene);
}


void StartScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
