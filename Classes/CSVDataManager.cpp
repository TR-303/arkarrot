#include "CommonDefines.h"
#include "CSVDataManager.h"

USING_NS_CC;

CSVDataManager* CSVDataManager::_single_instance = nullptr;

inline CSVDataManager::CSVDataManager() :levelInfos(4) {}

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
	FileUtils* fileUtils = FileUtils::getInstance();
	// 从resources目录下构建文件完整路径
	std::string csvFullPath = fileUtils->fullPathForFilename(path);
	std::ifstream file(csvFullPath);
	if (!file.is_open()) {
		cocos2d::log("file lost!exit...");
		exit(-1);
	}
	file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (!file.eof()) {
		string name, plist_path;
		int frame_cnt, cost, attack, range, bullet_frame_cnt, sell;
		float cooldown, rotate_speed, bullet_speed;
		std::getline(file, name, ',');
		std::getline(file, plist_path, ',');
		file >> frame_cnt; file.ignore(1, ',');
		file >> cost; file.ignore(1, ',');
		file >> sell; file.ignore(1, ',');
		file >> cooldown; file.ignore(1, ',');
		file >> attack; file.ignore(1, ',');
		file >> range; file.ignore(1, ',');
		file >> rotate_speed; file.ignore(1, ',');
		file >> bullet_frame_cnt; file.ignore(1, ',');
		file >> bullet_speed; file.ignore(1, '\n');
		towerInfos[name] = TowerInfo{ name,plist_path,frame_cnt,cost,sell,cooldown,attack,range,rotate_speed,bullet_frame_cnt,bullet_speed };
		file.peek();
	}
	file.close();
	return;
}

void CSVDataManager::loadMonsterData(const string& path)
{
	if (!visited_path.insert(path).second)return;
	FileUtils* fileUtils = FileUtils::getInstance();
	// 从resources目录下构建文件完整路径
	std::string csvFullPath = fileUtils->fullPathForFilename(path);
	std::ifstream file(csvFullPath);
	if (!file.is_open()) {
		cocos2d::log("file lost!exit...");
		exit(-1);
	}
	file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (!file.eof()) {
		string name, plist_path;
		int frame_cnt, lifepoint, damage, reward, speed;
		std::getline(file, name, ',');
		std::getline(file, plist_path, ',');
		file >> frame_cnt; file.ignore(1, ',');
		file >> speed; file.ignore(1, ',');
		file >> lifepoint; file.ignore(1, ',');
		file >> damage; file.ignore(1, ',');
		file >> reward; file.ignore(1, '\n');
		monsterInfos[name] = MonsterInfo{ name,plist_path,frame_cnt,speed,lifepoint,damage,reward };
		file.peek();
	}
	file.close();
	return;
}

void CSVDataManager::loadObjectData(const string& path)
{
	if (!visited_path.insert(path).second)return;
	FileUtils* fileUtils = FileUtils::getInstance();
	// 从resources目录下构建文件完整路径
	std::string csvFullPath = fileUtils->fullPathForFilename(path);
	std::ifstream file(csvFullPath);
	if (!file.is_open()) {
		cocos2d::log("file lost!exit...");
		exit(-1);
	}
	file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (!file.eof()) {
		string name, plist_path;
		int lifepoint, reward, sizex, sizey;
		std::getline(file, name, ',');
		std::getline(file, plist_path, ',');
		file >> lifepoint; file.ignore(1, ',');
		file >> sizex; file.ignore(1, ',');
		file >> sizey; file.ignore(1, ',');
		file >> reward; file.ignore(1, '\n');
		objectInfos[name] = ObjectInfo{ name,plist_path,lifepoint,Vec2(sizex,sizey),reward };
		file.peek();
	}
	file.close();
	return;
}

void CSVDataManager::loadLevelData(const string& path)
{
	if (!visited_path.insert(path).second)return;
	FileUtils* fileUtils = FileUtils::getInstance();
	// 从resources目录下构建文件完整路径
	std::string csvFullPath = fileUtils->fullPathForFilename(path);
	std::ifstream file(csvFullPath);
	if (!file.is_open()) {
		cocos2d::log("file lost!exit...");
		exit(-1);
	}
	file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (!file.eof()) {
		int lvl, wave_cnt, money, monster_cnt;
		string monster;
		file >> lvl; file.ignore(1, ',');
		file >> wave_cnt; file.ignore(1, ',');
		file >> money; file.ignore(1, ',');
		std::vector<std::pair<string, int>> waves;
		for (int i = 0; i < wave_cnt; ++i) {
			std::getline(file, monster, ',');
			file >> monster_cnt; file.ignore(1, ',');
			waves.push_back(std::make_pair(monster, monster_cnt));
		}
		levelInfos[lvl] = { lvl,wave_cnt,money,waves };
		file.peek();
	}
	file.close();
	return;
}

const TowerInfo& CSVDataManager::getTowerInfo(const string& name) {
	if (towerInfos.count(name) > 0)return towerInfos[name];
	else {
		CCLOG("wrong tower name");
		throw std::exception("");
	}
}

const MonsterInfo& CSVDataManager::getMonsterInfo(const string& name) {
	if (monsterInfos.count(name) > 0)return monsterInfos[name];
	else {
		CCLOG("wrong monster name");
		throw std::exception("");
	}
}

const ObjectInfo& CSVDataManager::getObjectInfo(const string& name)
{
	if (objectInfos.count(name) > 0)return objectInfos[name];
	else {
		CCLOG("wrong object name");
		throw std::exception("");
	}
}

const LevelInfo& CSVDataManager::getLevelInfo(int lvl)
{
	if (levelInfos.size() > lvl)return levelInfos[lvl];
	else {
		CCLOG("wrong level");
		throw std::exception("");
	}
}
