#pragma once
/*Sets oom walls, set items, enemies, doors, obstacles amount*/
#include <vector>
#include "Room.h"

using namespace std;

class RoomBuilder
{
public:
	RoomBuilder(int width, int heihgt);
	Room build();
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
	void createDoor(Room* room);
	void createTreasure(Room* room);
	void createHInnerWall(Room* room);
	void createVInnerWall(Room* room);
	void createEnemy(Room* room, int id);
};

