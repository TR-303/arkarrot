#include "ChooseMenuScene.h"
#include "ui/CocosGUI.h"
#include"StartMenuScene.h"

USING_NS_CC;

cocos2d::Scene* ChooseMenuScene::createScene() {
    return ChooseMenuScene::create();
}

bool ChooseMenuScene::init() {
    if (!Scene::init()) {
        return false;
    }

    // 初始化图片路径和索引
    imagePaths = { "Themes/scene/stages_theme1-hd/ss_map01.png",
                   "Themes/scene/stages_theme1-hd/ss_map02.png",
                   "Themes/scene/stages_theme1-hd/ss_map03.png" }; // 替换为实际的图片路径
    currentImageIndex = 0;

    // 创建并初始化图片精灵
    imageSprite = cocos2d::Sprite::create("Themes/scene/stages_bg-hd/ss_bg.png");
    imageSprite->setPosition(cocos2d::Vec2(480, 320)); // 假设中心位置
    this->addChild(imageSprite); // 将精灵添加到场景

    secondImageSprite = cocos2d::Sprite::create(imagePaths[currentImageIndex]);
    secondImageSprite->setPosition(cocos2d::Vec2(480, 320)); // 设置位置.
    this->addChild(secondImageSprite);

    // 图一按钮
    //auto buttonMap1 = cocos2d::ui::Button::create("Themes/scene/stages_theme1-hd/ss_map01.png");
    //buttonMap1->setPosition(cocos2d::Vec2(480, 320)); // 设置按钮位置
    //buttonMap1->addClickEventListener(CC_CALLBACK_1(ChooseMenuScene::buttonMap1Clicked, this));
    //this->addChild(buttonMap1);

    //// 图二按钮
    //auto buttonMap2 = cocos2d::ui::Button::create("Themes/scene/stages_theme1-hd/ss_map02.png");
    //buttonMap2->setPosition(cocos2d::Vec2(480, 100)); // 设置按钮位置
    //buttonMap2->addClickEventListener(CC_CALLBACK_1(ChooseMenuScene::buttonMap2Clicked, this));
    //this->addChild(buttonMap2);

    //// 图三按钮
    //auto buttonMap3 = cocos2d::ui::Button::create("Themes/scene/stages_theme1-hd/ss_map03.png");
    //buttonMap3->setPosition(cocos2d::Vec2(480, 100)); // 设置按钮位置
    //buttonMap3->addClickEventListener(CC_CALLBACK_1(ChooseMenuScene::buttonMap3Clicked, this));
    //this->addChild(buttonMap3);

    // 返回主菜单按钮
    auto buttonMainMenu = cocos2d::ui::Button::create("Themes/scene/stages_bg-hd/ss_back_normal.png", "Themes/scene/stages_bg-hd/ss_back_pressed.png", "Themes/scene/stages_bg-hd/ss_back_normal.png");
    buttonMainMenu->setPosition(cocos2d::Vec2(20, 620)); // 按钮的位置
    buttonMainMenu->addClickEventListener(CC_CALLBACK_1(ChooseMenuScene::buttonMainMenuClicked, this));
    this->addChild(buttonMainMenu);

    // 上一张地图按钮
    auto buttonLastMap = cocos2d::ui::Button::create("Themes/scene/recommend-hd/recommend_left_normal.png", "Themes/scene/recommend-hd/recommend_left_pressed.png", "Themes/scene/recommend-hd/recommend_left_normal.png");
    buttonLastMap->setPosition(cocos2d::Vec2(20, 300)); // 按钮的位置
    buttonLastMap->addClickEventListener(CC_CALLBACK_1(ChooseMenuScene::buttonLastMapClicked, this));
    this->addChild(buttonLastMap);

    // 下一张地图按钮
    auto buttonNextMap = cocos2d::ui::Button::create("Themes/scene/recommend-hd/recommend_right_normal.png", "Themes/scene/recommend-hd/recommend_right_pressed.png", "Themes/scene/recommend-hd/recommend_right_normal.png");
    buttonNextMap->setPosition(cocos2d::Vec2(940, 300)); // 按钮的位置
    buttonNextMap->addClickEventListener(CC_CALLBACK_1(ChooseMenuScene::buttonNextMapClicked, this));
    this->addChild(buttonNextMap);



    return true;
}

void ChooseMenuScene::changeImage(cocos2d::Ref* sender) {
    currentImageIndex++;
    if (currentImageIndex >= imagePaths.size()) {
        currentImageIndex = 0;
    }

    // 获取新图片的路径并更新精灵显示的图片
    std::string nextImagePath = imagePaths[currentImageIndex];
    imageSprite->setTexture(nextImagePath);
}

// 第一个按钮的回调函数
void ChooseMenuScene::buttonMap1Clicked(cocos2d::Ref* sender) {
    // 处理第一个按钮的点击事件
}

// 第二个按钮的回调函数
void ChooseMenuScene::buttonMap2Clicked(cocos2d::Ref* sender) {
    // 处理第二个按钮的点击事件
}

void ChooseMenuScene::buttonMap3Clicked(cocos2d::Ref* sender) {
    // 处理第二个按钮的点击事件
}

void ChooseMenuScene::buttonMainMenuClicked(cocos2d::Ref* sender) {
    auto scene = StartMenuScene::create();  // 创建 StartMenuScene 的实例
    cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(0.5, scene));  // 切换场景
}

void ChooseMenuScene::buttonLastMapClicked(cocos2d::Ref* sender) {
    if (currentImageIndex > 0) {
        currentImageIndex--;
    }
    else {
        currentImageIndex = imagePaths.size() - 1;  // 跳转到最后一张图片
    }

    // 获取新图片的路径并更新第二张图片精灵的显示的图片
    std::string previousImagePath = imagePaths[currentImageIndex];
    secondImageSprite->setTexture(previousImagePath);
}

void ChooseMenuScene::buttonNextMapClicked(cocos2d::Ref* sender) {
    if (currentImageIndex < imagePaths.size() - 1) {
        currentImageIndex++;
    }
    else {
        currentImageIndex = 0;  // 跳转到第一张图片
    }

    // 获取新图片的路径并更新第二张图片精灵的显示的图片
    std::string nextImagePath = imagePaths[currentImageIndex];
    secondImageSprite->setTexture(nextImagePath);
}