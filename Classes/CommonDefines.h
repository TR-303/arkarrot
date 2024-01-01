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

using std::string;