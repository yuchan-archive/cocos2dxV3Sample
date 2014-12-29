//
//  NewScene.h
//  FirstGame
//
//  Created by Ohashi Yusuke on 12/29/14.
//
//

#ifndef __FirstGame__NewScene__
#define __FirstGame__NewScene__

#include "cocos2d.h"

class NewScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    // implement the "static create()" method manually
    CREATE_FUNC(NewScene);
};
#endif /* defined(__FirstGame__NewScene__) */
