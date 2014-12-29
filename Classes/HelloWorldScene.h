#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer
{
private:
    unsigned int soundid;
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    cocos2d::Sprite *mySprite;
    
    void stopEffect(float dt);
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
    //void onTouchesBegan(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event);

    void Play(Ref *pSender);
    void HighScore(Ref *pSender);
    void Settings(Ref *pSender);
    
    void imageButton(Ref *pSender);
};

#endif // __HELLOWORLD_SCENE_H__
