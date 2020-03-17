#pragma once
#include <vector>
#include "Point.h"
using namespace std;

class RoomMapBuilder
{
public:
	RoomMapBuilder(int width, int heihgt);
	vector<vector<int>> build();
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
	void createDoor(vector<vector<int>>* map);
	bool createDoor(int column, int row, vector<vector<int>>* map);

	void createTreasure(vector<vector<int>>* map);
	void createHScale(vector<vector<int>>* map);
	void createVScale(vector<vector<int>>* map);
	void createEnemy(vector<vector<int>>* map, int id);
	Point getRandomInner(vector<vector<int>>* map);
};


