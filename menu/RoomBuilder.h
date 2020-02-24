#pragma once
#include "Room.h"
class RoomBuilder
{
public:
	RoomBuilder() {

	}
	Room build();
	void setObstacleCount(int count){
		this->obstacleCount = count<=0?0:count;	
	}
	void setDoorCount(int count) {
		this->doorCount = count<=0?1:count;
	}
	
private:
	int obstacleCount = 0;
	int doorCount = 1;
	int width = 45;
	int roomMap[15][45];
	int height = 15;
	void createRoomMap();
	void createDoor();
	void createHObstacle(int x, int y, int size);
	void createVObstacle(int x, int y, int size);
};

