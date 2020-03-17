#pragma once
/*Sets oom walls, set items, enemies, doors, obstacles amount*/
#include <vector>
#include "Room.h"
#include "RoomElementFactory.h"


using namespace std;

class RoomBuilder{
public:
	RoomBuilder(int width, int heihgt);
	Room* build(RoomElementFactory* elementFactory);
	void setScaleCount(int count);
	void setDoorCount(int count);
	void setTreasureCount(int count);
	void setEnemyCount(int count);

private:
	int scaleCount = 0;
	int enemyCount = 0;
	int treasureCount = 0;
	int doorCount = 1;
	int width = 45;
	int height = 15;
	void createDoor(Room* room, RoomElementFactory* elementFactory);
	bool createDoor(int column, int row, Room* room, RoomElementFactory* elementFactory);

	void createTreasure(Room* room, RoomElementFactory* elementFactory);
	void createHScale(Room* room, RoomElementFactory* elementFactory);
	void createVScale(Room* room, RoomElementFactory* elementFactory);
	void createEnemy(Room* room, RoomElementFactory* elementFactory, int id);
};

