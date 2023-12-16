#pragma once
#include "cocos2d.h"

#define DEBUG

#ifdef DEBUG
/*
* @brief 在场景中使用该函数，鼠标点击时显示鼠标位置坐标，仅在DEBUG定义时有效
*/
#define CREATE_POSITION_INDICATOR() \
auto touchListener = EventListenerTouchOneByOne::create();\
touchListener->onTouchBegan = [](Touch* touch, Event* event) {\
    Vec2 touchLocation = touch->getLocation();\
    CCLOG("mouse position:X = %.2f, Y = %.2f", touchLocation.x, touchLocation.y);\
    return true;\
};\
_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
#else
#define CREATE_POSITION_INDICATOR() 
#endif

using cocos2d::Director;
using cocos2d::Scene;
using cocos2d::Node;
using cocos2d::Animation;
using cocos2d::AnimationFrame;
using cocos2d::Animate;
using cocos2d::Sprite;
using cocos2d::SpriteFrame;
using cocos2d::SpriteFrameCache;
using cocos2d::Vector;
using cocos2d::log;

using std::string;