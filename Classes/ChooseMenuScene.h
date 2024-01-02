#pragma once
#include "cocos2d.h"
#include <vector>
#include<string>

class ChooseMenuScene : public cocos2d::Scene {
private:
    virtual bool init() override;
    /*
    * @brief 转到上一关的回调函数
    */
    void buttonLastMapClicked(cocos2d::Ref* sender);
    /*
    * @brief 转到下一关的回调函数
    */
    void buttonNextMapClicked(cocos2d::Ref* sender);
    /*
    * @brief 回到主菜单的回调函数
    */
    void buttonMainMenuClicked(cocos2d::Ref* sender);
    /*
    * @brief 开始游戏的回调函数
    * @todo 补全游戏场景
    */
    void buttonStartClicked(cocos2d::Ref* sender);
    //当前展示的关卡编号
    int currentStageIndex;
    std::vector<cocos2d::Sprite*> stageSprites;
public:
    CREATE_FUNC(ChooseMenuScene);
};