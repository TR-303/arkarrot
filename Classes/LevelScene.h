#pragma once
#include <vector>
#include "CommonDefines.h"
#include "CSVDataManager.h"
#include "ui/UIButton.h"

constexpr const int map_sizex = 960;
constexpr const int map_sizey = 640;
constexpr const int map_col = 12;
constexpr const int map_row = 8;
constexpr const int side_length = 80;

class TowerBase;
class Monster;
class VictimBase;
class Object;
class Monster;
class Carrot;
/*
* @brief 单例关卡场景，通过调用init来创建特定关卡
*/
class LevelScene :public cocos2d::Scene {
private:
	using _Base = Scene;

	//关于单例模式实现
public:
	static LevelScene* _single_instance;
	LevelScene();
public:
	/*
	* @brief 获得关卡场景的单例对象
	*/
	static LevelScene* LevelScene::getInstance();

	//关于关卡信息
private:
	LevelInfo levelInfo;
	void onExitTransitionDidStart()override;
public:
	/*
	* @brief 创建关卡场景，加载Object对象，加载行进路线，加载出怪时间轴，渲染背景，渲染路径
	* @param 关卡编号
	*/
	virtual bool init(int lvl);

	//场景布局
public:
	enum RegionState {
		EMPTY, OBJECT, TOWER, UNAVAILABLE
	};
	std::vector<std::vector<RegionState>> regionStates;
private:
	struct TowerInfo {
		int _what;
		int _level;
		TowerBase* _ptrTower;
		TowerInfo(int id = -1, int lv = 0, TowerBase* ptr = nullptr) :_what(id), _level(lv), _ptrTower(ptr) {}
	};
	std::vector<std::vector<TowerInfo>> towerStates;


	//关于检查点
private:
	std::vector<cocos2d::Vec2> checkPoints;
public:
	const std::vector<cocos2d::Vec2>& getCheckPoints()const;

	//关于场景怪物
private:
	cocos2d::Vector<Monster*> monsters;
public:
	const cocos2d::Vector<Monster*>& getMonsters()const;
	void eraseMonster(Monster* mons);

	//关于场景防御塔
private:
	cocos2d::Vector<TowerBase*> towers;
public:
	const cocos2d::Vector<TowerBase*>& getTowers()const;

	//关于场景金币
private:
	int money;
	cocos2d::Label* moneyLabel;  // 用于显示金币数量的Label
public:
	void updateMoneyLabel(float delta);
	int getMoney()const;
	/*
	* @brief 消耗金币，如果有足够的金币返回true，否则返回false
	*/
	bool consumeMoney(int cost);
	void addMonsy(int reward);


	//关于出怪时间轴
private:
	int currentWave;
	cocos2d::Label* waveLabel;  // 用于显示波次的Label
	void updateWaveLabel(float delta);
	void AllWavesEnd();
	void lose();
public:
	int getCurrentWave()const;
	/*
	* @brief 触发下一波怪物
	*/
	void gotoNextWave();

	//关于萝卜
private:
	Carrot* carrot;
public:
	Carrot* getCarrot()const;

	//关于建造和升级
private:
	int hasMenu = 0;
	cocos2d::Sprite* selectBox;
	cocos2d::ui::Button* buildButtonBottle;
	cocos2d::ui::Button* buildButtonShit;
	cocos2d::ui::Button* buildButtonStar;
	cocos2d::ui::Button* upgradeButton;
	cocos2d::ui::Button* removeButton;
	cocos2d::EventListenerTouchOneByOne* touchListener;
	void menuClear();
public:
	void buildMenu(cocos2d::Vec2 pos);
	void upgradeMenu(cocos2d::Vec2 pos);
	bool tryBuildorUpgrade(cocos2d::Touch* touch, cocos2d::Event* event);

	//关于嘲讽
private:
	VictimBase* tauntedTarget;
public:
	VictimBase* getTauntedTarget()const;
	void setTauntedTarget(VictimBase* target);

};