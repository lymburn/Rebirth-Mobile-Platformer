//
//  TitleScene.cpp
//  Rebirth
//
//  Created by Eugene Lu on 2017-06-13.
//
//

#include "TitleScene.hpp"
#include "SimpleAudioEngine.h"


USING_NS_CC;

Scene* TitleScene::createScene()
{
    return TitleScene::create();
}

// on "init" you need to initialize your instance
bool TitleScene::init()
{
    //super init first
    if ( !Scene::init() )
    {
        return false;
    }

    //Creates title text and tap to play
    TextManager TextCreator(this);
    TextCreator.createTitle();
    TextCreator.createTapToPlay();

    //Create the background
    ImageManager ImageCreator(this);
    ImageCreator.createTitleBackground();

    ActionPerformer PerformActions;
    PerformActions.fadeInAndOut(TextCreator.getTapToPlay());
    
    
    auto listener1 = EventListenerTouchOneByOne::create();
    listener1->setSwallowTouches(true);
    // trigger when you push down
    
    
    listener1->onTouchBegan = [](Touch* touch, Event* event){
        auto scene = TutorialScene::createScene();
        Director::getInstance()->replaceScene(scene);
        return true; // if you are consuming it
    };
     
    
    // Add listener
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, this);
    
    return true;
    
}


