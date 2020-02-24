#pragma once
class RoomMapBuilder
{
public:
	RoomMapBuilder() {

	}
	int* build(int roomMap[15][45]);
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
	int height = 15;
	void createRoomMap(int roomMap[15][45]);
	void createDoor(int roomMap[15][45]);
	void createHObstacle(int roomMap[15][45],int x, int y, int size);
	void createVObstacle(int roomMap[15][45],int x, int y, int size);
};

