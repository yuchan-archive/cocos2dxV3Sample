#include "HelloWorldScene.h"
#include <SimpleAudioEngine.h>

#include "NewScene.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    mySprite = Sprite::create("CloseNormal.png");
    mySprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
    
    this->addChild(mySprite);
    // auto action = MoveBy::create(3, Point(50,0));
    // auto action = MoveTo::create(3, Point(100, 300));
    // auto action = JumpBy::create(3, Point(100, 300), 20, 5);
    // auto action = JumpTo::create(3, Point(200,400), 20, 5);
    // auto action = RotateBy::create(3, 90);
    //auto action = TintBy::create(3, -255, -255, 0);
    //mySprite->runAction(action);
    
//    CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(1.5);
//    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/Collide.wav");
//    soundid = CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/Collide.wav", true);

    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("audio/mainMainMusic.mp3");
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("audio/mainMainMusic.mp3", true);
    
    //this->schedule(schedule_selector(HelloWorld::stopEffect), 3.0);
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    

    auto menu_item_1 = MenuItemFont::create("Play", CC_CALLBACK_1(HelloWorld::Play, this));
    auto menu_item_2 = MenuItemFont::create("HighScore", CC_CALLBACK_1(HelloWorld::HighScore, this));
    auto menu_item_3 = MenuItemFont::create("Settings", CC_CALLBACK_1(HelloWorld::Settings, this));
    auto menu_item_4 = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(HelloWorld::imageButton, this));
    
    auto *menu = Menu::create(menu_item_1, menu_item_2, menu_item_3, menu_item_4, NULL);
    menu->alignItemsVertically();
    
    this->addChild(menu);
    
    return true;
}

void HelloWorld::imageButton(cocos2d::Ref *pSender)
{
    
}

void HelloWorld::Play(cocos2d::Ref *pSender)
{
    auto scene = NewScene::createScene();
    Director::getInstance()->pushScene(scene);
}

void HelloWorld::HighScore(cocos2d::Ref *pSender)
{
    
}

void HelloWorld::Settings(cocos2d::Ref *pSender)
{
    
}

bool HelloWorld::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    CCLOG("onTouchBegan x = %f, y = %f", touch->getLocation().x, touch->getLocation().y);
    return true;
}

void HelloWorld::stopEffect(float dt)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
