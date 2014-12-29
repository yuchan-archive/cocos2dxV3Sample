//
//  NewScene.cpp
//  FirstGame
//
//  Created by Ohashi Yusuke on 12/29/14.
//
//

#include "NewScene.h"
#include <cocostudio/CocoStudio.h>
#include <ui/CocosGUI.h>

USING_NS_CC;

Scene* NewScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = NewScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool NewScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    cocos2d::Node *node = CSLoader::createNode("CocosProject1/res/MainScene.csb");
    this->addChild(node);
    auto button = (ui::Button *)node->getChildByName<ui::Button*>("Button");
    if (button) {
        button->addClickEventListener([](Ref *ref) {
            // ボタン押した時の処理
            Director::getInstance()->popScene();
        });
        CCLOG("button exists.");
    }

    return true;
}