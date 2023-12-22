#pragma once
#include "CommonDefines.h"
#include <unordered_set>
#include <unordered_map>
#include <fstream>
#include <filesystem>

struct MonsterInfo {
	string name;
	string plist_path;
	int frame_cnt;
	float speed;
	int lifepoint;
	int damage;
};

struct TowerInfo {
	string name;
	string plist_path;
	int frame_cnt;
	int cost;
	float cooldown;
	int attack;
	int range;
	float rotate_speed;

	int bullet_frame_cnt;
	float bullet_speed;
};

class CSVDataManager {
private:
	//单例类指针
	static CSVDataManager* _single_instance;

	std::unordered_set<string> visited_path;
	std::unordered_map<string, TowerInfo> towerInfos;
	std::unordered_map<string, MonsterInfo> monsterInfos;

	//私有构造函数，不能在外部创建此类
	CSVDataManager();
public:
	/*
	* @brief 获取csv数据加载器的单例对象
	*/
	static CSVDataManager* getInstance();
	/*
	* @brief 加载防御塔的数据
	* @param towers.csv的路径
	*/
	void loadTowerData(const string& path);
	/*
	* @brief 加载怪物的数据
	* @param monsters.csv的路径
	*/
	void loadMonsterData(const string& path);
	/*
	* @brief 获得指定塔的数据
	* @param 塔的名称
	*/
	const TowerInfo& getTowerInfo(const string& name);
	/*
	* @brief 获得指定怪物的数据
	* @param 怪物的名称
	*/
	const MonsterInfo& getMonsterInfo(const string& name);
};