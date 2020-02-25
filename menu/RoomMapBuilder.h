#pragma once
#include <vector>
#include "RoomElement.h"
using namespace std;

const RoomElement room_wall = RoomElement(1, 219, false, 0);
const RoomElement room_door = RoomElement(-1, ' ', true, 5);
const RoomElement room_obstacle = RoomElement(2, 178, false, 0);
const RoomElement room_treasure = RoomElement(3, 158, true, 2);
const RoomElement room_inner = RoomElement(0, ' ', true, 0);
const RoomElement room_enemy= RoomElement(4, 172, false, 10);

class RoomMapBuilder
{
public:
	RoomMapBuilder(int width, int heihgt) {
		this->width = width;
		this->height = height;
	}
	vector<vector<RoomElement>> build();

	void setObstacleCount(int count) {
		this->obstacleCount = count <= 0 ? 0 : count;
	}
	void setDoorCount(int count) {
		this->doorCount = count <= 0 ? 1 : count;
	}
	void setTreasure(int count) {
		this->treasureCount = count <= 0 ? 0 : count;
	}


private:
	int obstacleCount = 0;
	int treasureCount = 0;
	int doorCount = 1;
	int width = 45;
	int height = 15;
	void createDoor(std::vector<std::vector<RoomElement>>* tmpRows);
	void createTreasure(std::vector<std::vector<RoomElement>>* tmpRows);
	void createHObstacle(std::vector<std::vector<RoomElement>>* tmpRows);
	void createVObstacle(vector<std::vector<RoomElement>>* tmpRows);
	bool canObstalace(vector<std::vector<RoomElement>>* tmpRows, int row, int column);
};

