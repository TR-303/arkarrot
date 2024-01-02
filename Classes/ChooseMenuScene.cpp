#include "ChooseMenuScene.h"
#include "ui/CocosGUI.h"
#include "StartMenuScene.h"
#include "LevelScene.h"

USING_NS_CC;

bool ChooseMenuScene::init() {
    if (!Scene::init()) return false;
    
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Scenes/choosemenuscene/stages.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Scenes/choosemenuscene/stages_bg.plist");

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Vec2 center = Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);

    currentStageIndex = 1;

    //1-index占位
    stageSprites.push_back(Sprite::create());
    //不止3关的话要修改这里
    for (int i = 1; i <= 3; ++i) {
        auto stageSprite = Sprite::createWithSpriteFrameName(StringUtils::format("ss_map_%d.png", i));
        if (i == 1)stageSprite->setPosition(center);
        else stageSprite->setPosition(center + Vec2(visibleSize.width, 0));
        this->addChild(stageSprite, 1);
        stageSprites.push_back(stageSprite);
    }

    //添加背景
    auto background = Sprite::createWithSpriteFrameName("ss_bg.png");
    background->setPosition(center);
    this->addChild(background);

    // 返回主菜单按钮
    auto buttonMainMenu = ui::Button::create("Scenes/choosemenuscene/buttons/ss_back_normal.png", "Scenes/choosemenuscene/buttons/ss_back_pressed.png");
    buttonMainMenu->setPosition(cocos2d::Vec2(20, 620)); 
    buttonMainMenu->addClickEventListener(CC_CALLBACK_1(ChooseMenuScene::buttonMainMenuClicked, this));
    this->addChild(buttonMainMenu, 10);

    // 上一张地图按钮
    auto buttonLastMap = ui::Button::create("Scenes/choosemenuscene/buttons/left_normal.png", "Scenes/choosemenuscene/buttons/left_pressed.png");
    buttonLastMap->setPosition(cocos2d::Vec2(20, 300)); 
    buttonLastMap->addClickEventListener(CC_CALLBACK_1(ChooseMenuScene::buttonLastMapClicked, this));
    this->addChild(buttonLastMap, 10);

    // 下一张地图按钮
    auto buttonNextMap = ui::Button::create("Scenes/choosemenuscene/buttons/right_normal.png", "Scenes/choosemenuscene/buttons/right_pressed.png");
    buttonNextMap->setPosition(cocos2d::Vec2(940, 300));
    buttonNextMap->addClickEventListener(CC_CALLBACK_1(ChooseMenuScene::buttonNextMapClicked, this));
    this->addChild(buttonNextMap, 10);

    //开始按钮
    auto buttonStart = ui::Button::create("Scenes/choosemenuscene/buttons/ss_play_normal.png", "Scenes/choosemenuscene/buttons/ss_play_pressed.png");
    buttonStart->setPosition(center - cocos2d::Vec2(0, 200));
    buttonStart->addClickEventListener(CC_CALLBACK_1(ChooseMenuScene::buttonStartClicked, this));
    this->addChild(buttonStart, 10);

    return true;
}

void ChooseMenuScene::buttonMainMenuClicked(cocos2d::Ref* sender) {
    auto scene = StartMenuScene::create();  // 创建 StartMenuScene 的实例
    cocos2d::Director::getInstance()->popScene();  // 切换场景
}

void ChooseMenuScene::buttonStartClicked(cocos2d::Ref* sender){
    auto scene = LevelScene::getInstance();
    scene->init(currentStageIndex);
    cocos2d::Director::getInstance()->pushScene(cocos2d::TransitionFade::create(0.5, scene));
}

void ChooseMenuScene::buttonLastMapClicked(cocos2d::Ref* sender) {
    if (currentStageIndex == 1)return;
    //点击后禁用按钮一秒
    auto button = static_cast<cocos2d::ui::Button*>(sender);
    button->setTouchEnabled(false);
    this->scheduleOnce([=](float dt) {
        button->setTouchEnabled(true);
        }, 1.0f, "enableButtonTag");

    stageSprites[currentStageIndex - 1]->runAction(MoveBy::create(1, Vec2(Director::getInstance()->getVisibleSize().width, 0)));
    stageSprites[currentStageIndex]->runAction(MoveBy::create(1, Vec2(Director::getInstance()->getVisibleSize().width, 0)));
    --currentStageIndex;
}

void ChooseMenuScene::buttonNextMapClicked(cocos2d::Ref* sender) {
    //如果不止三关这里要改
    if (currentStageIndex == 3)return;
    //点击后禁用按钮一秒
    auto button = static_cast<cocos2d::ui::Button*>(sender);
    button->setTouchEnabled(false);
    this->scheduleOnce([=](float dt) {
        button->setTouchEnabled(true);
        }, 0.5f, "enableButtonTag");

    stageSprites[currentStageIndex + 1]->runAction(MoveBy::create(0.5, Vec2(-Director::getInstance()->getVisibleSize().width, 0)));
    stageSprites[currentStageIndex]->runAction(MoveBy::create(0.5, Vec2(-Director::getInstance()->getVisibleSize().width, 0)));
    ++currentStageIndex;
}