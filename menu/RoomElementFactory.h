#pragma once
#include "GameDef.h"
#include "RoomElement.h"
#include "Door.h"
#include "Enemy.h"
#include "Player.h"
#include "Enemy.h"

class RoomElementFactory {
public:
	RoomElementFactory();

	RoomElement* getWall() {
		return wall;
	}

	RoomElement* getInner() {
		return inner;
	}

	RoomElement* getScale() {
		return scale;
	}

	Door* getDoor() {
		return door;
	}

	Gun* getGun(int range, int magazine) {
		return new Gun(range, magazine);
	}

	RoomElement* getTreasure() {
		return treasure;
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
	int lastSelectedEnemy = -1;
	RoomElement* inner = new  RoomElement(id_inner, ' ', true);
	RoomElement* wall = new  RoomElement(id_wall, static_cast<char>(219), false);
	RoomElement* scale = new RoomElement(id_wall, static_cast<char>(219), false);
	Door* door = new Door();
	RoomElement* treasure = new RoomElement(id_treasure, static_cast<char>(158), true, 2);
	//Player* player = new Player();
};

