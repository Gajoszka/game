#pragma once
#include <type_traits>
#include <xiosbase>
#include <vector>
#include "RoomElement.h"
#include "Enemy.h"

using namespace std;

const RoomElement room_wall = RoomElement(1, 219, false, 0);
const RoomElement room_door = RoomElement(-1, ' ', true, 5);
const RoomElement room_scale = RoomElement(2, 178, false, 0);
const RoomElement room_treasure = RoomElement(3, 158, true, 2);
const RoomElement room_inner = RoomElement(0, ' ', true, 0);
const RoomElement room_enemy = RoomElement(4, 172, false, 10);
//const RoomElement failed = RoomElement(-11, ' ', false, 0);

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
	RoomMap(int width, int height) {
		this->width = width;
		this->height = height;;
		for (int row = 0; row < height; row++) {
			vector<RoomElement> tmp;
			for (int i = 0; i < width; i++) {
				tmp.push_back(room_inner);
			}
			roomMap.push_back(move(tmp));
		}
	}
	bool set(int column, int row, RoomElement el) {
		if (row >= 0 && row < height && column >= 0 && column < width) {
			roomMap[row][column] = el;
			return true;
		}
		return false;
	}

	RoomElement* get(int column, int row) {
		if (row >= 0 && row < height && column >= 0 && column < width) {
			return &roomMap[row][column];
		}
		return nullptr;
	}
	bool setWall(int column, int row) {
		return set(column, row, room_wall);
	}

	bool setInner(int column, int row) {
		return set(column, row, room_inner);
	}

	bool setDoor(int column, int row) {
		if ((column == 0 || column == width - 1) && (row == 1 && row == height - 1)) {
			set(column, row, room_door);
			return true;
		}
		return false;
	}

	bool setEnemy(int column, int row, Enemy* enemy) {
		if (canPut(column, row))
			return set(column, row, *enemy);
		return false;
	}

	bool setScale(int column, int row) {
		if (canPut(column, row))
			return set(column, row, room_scale);
		return false;
	}

	bool setTreacure(int column, int row) {
		if (canPut(column, row))
			return set(column, row, room_treasure);
		return false;
	}

	bool canMove(int column, int row) {
		return (*get(column, row)).canPass;
	}

	bool isDoor(int column, int row) {
		return (*get(column, row)).id==room_door.id;
	}

	int getScore(int column, int row) {
		return (*get(column, row)).score;
	}

	int getWidth() {
		return width;
	}

	int getHeight() {
		return height;
	}

private:
	int width;
	int height;
	vector<vector<RoomElement>> roomMap;
	bool canPut(int row, int column);
};



