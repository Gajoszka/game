#pragma once
#include <vector>
using namespace std;

class RoomMapBuilder
{
public:
	RoomMapBuilder(int width,int heihgt) {
		this->width = width;
		this->height = height;
	}
	vector<vector<int>> build();

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
	void createDoor(std::vector<std::vector<int>> *tmpRows);
	void createTreasure(std::vector<std::vector<int>> *tmpRows);
	void createHObstacle(std::vector<std::vector<int>> *tmpRows);
	void createVObstacle(vector<std::vector<int>> *tmpRows);
	bool canObstalace(vector<std::vector<int>>* tmpRows, int row, int column);
};

