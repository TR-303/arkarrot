#pragma once
#include "cocos2d.h"
#include <vector>
#include<string>

class ChooseMenuScene : public cocos2d::Scene {
public:
    static cocos2d::Scene* createScene();
    virtual bool init() override;

    // 按钮点击事件处理器
    void changeImage(cocos2d::Ref* sender);
    void buttonMap1Clicked(cocos2d::Ref* sender);
    void buttonMap2Clicked(cocos2d::Ref* sender);
    void buttonMap3Clicked(cocos2d::Ref* sender);
    void buttonLastMapClicked(cocos2d::Ref* sender);
    void buttonNextMapClicked(cocos2d::Ref* sender);
    void buttonMainMenuClicked(cocos2d::Ref* sender);

    // implement the "static create()" method manually
    CREATE_FUNC(ChooseMenuScene);

private:
    cocos2d::Sprite* imageSprite; // 用于显示图片的精灵
    cocos2d::Sprite* secondImageSprite; // 用于显示第二张图片的精灵
    int currentImageIndex; // 当前图片索引
    std::vector<std::string> imagePaths; // 图片路径数组

};