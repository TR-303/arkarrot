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
	int speed;
	int lifepoint;
	int damage;
	int reward;
};

struct TowerInfo {
	string name;
	string plist_path;
	int frame_cnt;
	int cost;
	int sell;
	float cooldown;
	int attack;
	int range;
	float rotate_speed;

	int bullet_frame_cnt;
	float bullet_speed;
};

struct ObjectInfo {
	string name;
	string plist_path;
	int lifepoint;
	cocos2d::Vec2 size;
	int reward;
};

struct LevelInfo {
	int lvl;
	int wave_cnt;
	int money;
	std::vector<std::pair<string, int>> waves;
};
/*
* @brief 单例模式，管理塔和怪物的数据和素材
*/
class CSVDataManager {
private:
	//单例类指针
	static CSVDataManager* _single_instance;

	std::unordered_set<string> visited_path;
	std::unordered_map<string, TowerInfo> towerInfos;
	std::unordered_map<string, MonsterInfo> monsterInfos;
	std::unordered_map<string, ObjectInfo> objectInfos;
	std::vector<LevelInfo> levelInfos;

	//私有构造函数，不能在外部创建此类
	CSVDataManager();
public:
	/*
	* @brief 获取csv数据加载器的单例对象
	*/
	static CSVDataManager* getInstance();
	/*
	* @brief 加载防御塔的数据
	* @param towers.csv相对于resources的路径
	*/
	void loadTowerData(const string& path);
	/*
	* @brief 加载怪物的数据
	* @param monsters.csv相对于resources的路径
	*/
	void loadMonsterData(const string& path);
	/*
	* @brief 加载障碍物的数据
	* @param objects.csv相对于resources的路径
	*/
	void loadObjectData(const string& path);
	/*
	* @brief 加载关卡的数据
	* @param levels.csv相对于resources的路径
	*/
	void loadLevelData(const string& path);
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
	/*
	* @brief 获得指定障碍物的数据
	* @param 障碍物的名称
	*/
	const ObjectInfo& getObjectInfo(const string& name);
	/*
	* @brief 获得指定关卡的数据
	* @param 关卡编号
	*/
	const LevelInfo& getLevelInfo(int lvl);
};