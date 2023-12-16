#include "CSVDataManager.h"
#include "CommonDefines.h"

USING_NS_CC;

CSVDataManager* CSVDataManager::_single_instance = nullptr;

CSVDataManager::CSVDataManager() {}

CSVDataManager* CSVDataManager::getInstance()
{
	if (!_single_instance) {
		_single_instance = new CSVDataManager();
	}
	return _single_instance;
}

void CSVDataManager::loadTowerData(const string& path)
{
	if (!visited_path.insert(path).second)return;
	std::ifstream file(path);
	if (!file.is_open()) {
		cocos2d::log("file lost!exit...");
		exit(-1);
	}
	file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (!file.eof()) {
		string name, plist_path;
		int frame_cnt, cost, attack, bullet_frame_cnt;
		float cool_down, bullet_speed;
		std::getline(file, name, ',');
		std::getline(file, plist_path, ',');
		file >> frame_cnt; file.ignore(1, ',');
		file >> cost; file.ignore(1, ',');
		file >> cool_down; file.ignore(1, ',');
		file >> attack; file.ignore(1, ',');
		file >> bullet_frame_cnt; file.ignore(1, ',');
		file >> bullet_speed; file.ignore(1, '\n');
		towerInfos[name] = TowerInfo{ name,plist_path,frame_cnt,cost,cool_down,attack,bullet_frame_cnt,bullet_speed };
		file.peek();
	}
	file.close();
	return;
}

void CSVDataManager::loadMonsterData(const string& path)
{
	if (!visited_path.insert(path).second)return;
	std::ifstream file(path);
	if (!file.is_open()) {
		cocos2d::log("file lost!exit...");
		exit(-1);
	}
	file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (!file.eof()) {
		string name, plist_path;
		int frame_cnt, lifepoint, damage;
		float speed;
		std::getline(file, name, ',');
		std::getline(file, plist_path, ',');
		file >> frame_cnt; file.ignore(1, ',');
		file >> speed; file.ignore(1, ',');
		file >> lifepoint; file.ignore(1, ',');
		file >> damage; file.ignore(1, '\n');
		monsterInfos[name] = MonsterInfo{ name,plist_path,frame_cnt,speed,lifepoint,damage };
		file.peek();
	}
	file.close();
	return;
}
