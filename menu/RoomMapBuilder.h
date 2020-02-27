#pragma once
/*Sets oom walls, set items, enemies, doors, obstacles amount*/
#include <vector>
#include "RoomMap.h"

using namespace std;

class RoomMapBuilder
{
public:
	RoomMapBuilder(int width, int heihgt);
	RoomMap build();
	void setScaleCount(int count);
	void setDoorCount(int count);
	void setTreasureCount(int count);
	void setEnemyCount(int count);

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

