#pragma once
#include "GameDef.h"
#include "RoomElement.h"
#include "Door.h"
#include "Enemy.h"
#include "Player.h"
#include "Enemy.h"
/* Creating room elements */

class RoomElementFactory {
public:
	RoomElementFactory();

	RoomElement* getWall() {
		return wall;
	}

	RoomElement* getInner() {
		return inner;
	}

	RoomElement* get(int id);

	RoomElement* getScale() {
		return scale;
	}

	Door* getDoor() {
		return pDoor;
	}

	Gun* getGun();

	RoomElement* getTreasure() {
		return pTreasure;
	}

	/*Player* getPlayer() {
		return player;
	}*/

	Enemy* getEnemy(int id) {
		Enemy* enemy = new Enemy(id);
		enemys.push_back(enemy);
		return enemy;
	}

	Enemy* getEnemyById(int id);

	void removeEnemy(Enemy* enemy);

	void clearEnemys();
	void clearGuns();

	size_t getEnemyCount() {
		return enemys.size();
	}

	Enemy* getRandEnemy() {
		if (enemys.size()==0)
			return nullptr;
		if (enemys.size() == 1)
			return enemys[0];
		int selectedEnemy = 0;
		while ( lastSelectedEnemy == (selectedEnemy = rand() % enemys.size())); // chooses only one enemy to move
		lastSelectedEnemy = selectedEnemy;
		return enemys[selectedEnemy];
	}

	~RoomElementFactory();
private:
	vector<Enemy*> enemys;
	vector<Gun*> guns;
	int lastSelectedEnemy = -1;
	RoomElement* inner = new  RoomElement(id_inner, ' ', true);
	RoomElement* wall = new  RoomElement(id_wall, static_cast<char>(219), false);
	RoomElement* scale = new RoomElement(id_wall, static_cast<char>(219), false);
	Door* pDoor = new Door();
	RoomElement* pTreasure = new RoomElement(id_treasure, static_cast<char>(158), true, 1);
	//Player* player = new Player();
};