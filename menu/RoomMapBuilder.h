#pragma once

class RoomMapBuilder
{
public:
	RoomMapBuilder() {

	}
	std::vector<int> build();
	void setObstacleCount(int count){
		this->obstacleCount = count<=0?0:count;	
	}
	void setDoorCount(int count) {
		this->doorCount = count<=0?1:count;
	}
	void setTreasure(int count){
		this->treasureCount = count <= 0 ? 0 : count;
}
	
private:
	int obstacleCount = 0;
	int treasureCount = 0;
	int doorCount = 1;
	int width = 45;
	int height = 15;
	void createRoomMap(int roomMap[15][45]);
	void createDoor(int roomMap[15][45]);
	void createTreasure(int roomMap[15][45]);
	void createHObstacle(int roomMap[15][45],int x, int y, int size);
	void createVObstacle(int roomMap[15][45],int x, int y, int size);
};

