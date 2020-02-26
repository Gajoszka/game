#pragma once
#include <vector>
#include "RoomMap.h"

//using namespace std;

class RoomMapBuilder
{
public:
	RoomMapBuilder(int width, int heihgt) {
		this->width = width;
		this->height = height;
	}
	RoomMap build();

	void setObstacleCount(int count) {
		this->obstacleCount = count <= 0 ? 0 : count;
	}
	void setDoorCount(int count) {
		this->doorCount = count <= 0 ? 1 : count;
	}
	void setTreasureCount(int count) {
		this->treasureCount = count <= 0 ? 0 : count;
	}
	void setEnemyCount(int count) {
		this->enemyCount = count <= 0 ? 0 : count;
	}

private:
	int obstacleCount = 0;
	int enemyCount = 0;
	int treasureCount = 0;
	int doorCount = 1;
	int width = 45;
	int height = 15;
	void createDoor(RoomMap* roomMap);
	void createTreasure(RoomMap* roomMap);
	void createHInnerWall(RoomMap* roomMap);
	void createVInnerWall(RoomMap* roomMap);
	void createEnemy(RoomMap* roomMap, int id);
};

