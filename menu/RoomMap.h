#pragma once
#include <type_traits>
#include <xiosbase>
#include <vector>
#include "RoomElement.h"
#include "Enemy.h"
#include "Player.h"
#include "GameAction.h"

using namespace std;

const RoomElement room_wall = RoomElement(1, 219, false, 0);
const RoomElement room_door = RoomElement(-1, ' ', true, 5);
const RoomElement room_scale = RoomElement(2, 178, false, 0);
const RoomElement room_treasure = RoomElement(3, 158, true, 2);
const RoomElement room_inner = RoomElement(0, ' ', true, 0);
const RoomElement room_enemy = RoomElement(4, 172, false, 10);
const RoomElement failed = RoomElement(-11, ' ', false, 0);

//template<typename Base>
//class GenericClass
//{
//	static_assert(std::is_base_of<RoomElement, T>::value, "T must inherit from SomeBase");
//	void set(RoomElement el) {
//		this.el = el;
//	}
//	bool isEnemy() {
//		el.getId > 100;
//	}
//private:
//	RoomElement el;
//
//};

class RoomMap {
public:
	RoomMap(int width, int height);	
	bool set(int column, int row, RoomElement el);
	RoomElement get(int column, int row);
	bool setWall(int column, int row);
	bool setInner(int column, int row);
	bool setDoor(int column, int row);
	bool setEnemy(int column, int row, Enemy enemy);
	bool moveEnemy(int columnStep, int rowStep, Enemy enemy);
	bool setPlayer(int column, int row, Player* player);
	bool setPlayer(Player* player);
	bool setScale(int column, int row);
	bool setTreacure(int column, int row);
	bool canMove(int column, int row);
	bool isDoor(int column, int row);
	bool isEnemy(int column, int row);
	Enemy getEnemy(int column, int row);
	Enemy getEnemy(int id);

	int getScore(int column, int row) {
		return get(column, row).score;
	}

	char getIcon(int column, int row) {
		return get(column, row).icon;
	}

	int getWidth() {
		return width;
	}

	int getHeight() {
		return height;
	}

	vector<Enemy> getEnemys() {
		return enemys;
	}

	int getEnemyCount() {
		return enemys.size();
	}
	GameAction movePlayer(int columnStep, int rowStep, Player* player);
	~RoomMap();
private:
	int width;
	int height;
	vector<vector<RoomElement>> roomMap;
	bool canPut(int row, int column);
	vector<Enemy> enemys;
};



