#include "RoomMapBuilder.h"
#include "GameDef.h"
#include <windows.h>

RoomMapBuilder::RoomMapBuilder(int width, int heihgt) {
	this->width = width;
	this->height = height;
}

void RoomMapBuilder::setScaleCount(int count) {
	this->scaleCount =  abs( count); 
}
void RoomMapBuilder::setDoorCount(int count) {
	this->doorCount = count <= 0 ? 1 : count;
}
void RoomMapBuilder::setTreasureCount(int count) {
	this->treasureCount = abs(count);;
}
void RoomMapBuilder::setEnemyCount(int count) {
	this->enemyCount = abs(count);;
}
vector<vector<int>> RoomMapBuilder::build()
{
	vector<vector<int>> roomMap;
	for (int row = 0; row < height; row++) {
		vector<int> tmp;
		for (int i = 0; i < width; i++) {
			tmp.push_back(id_inner);
		}
		roomMap.push_back(move(tmp));
	}
	//horizontal wall
	for (int column = 0; column < width; column++) {
		roomMap[0][column] = id_wall;
		roomMap[height - 1][column] = id_wall;;
	}
	//vertical wall
	for (int row = 0; row < height; row++) {
		roomMap[row][0] = id_wall;
		roomMap[row][width - 1] = id_wall;;
	}

	for (int i = 0; i < this->doorCount; i++) {
		createDoor(&roomMap);
	}

	for (int i = 0; i < this->scaleCount; i++) {
		createHScale(&roomMap);

	}
	for (int i = 0; i < this->scaleCount - 1; i++) {
		createVScale(&roomMap);
	}

	for (int i = 0; i < this->enemyCount; i++) {
		createEnemy(&roomMap, i);
	}
	createTreasure(&roomMap);
	return roomMap;
}

void RoomMapBuilder::createDoor(vector<vector<int>>* map) {

	bool ok = false;
	while (!ok) {
		switch (rand() % 4)  //which wall
		{
		case 0:
			ok = createDoor(rand() % (width - 3) + 2, 0, map);
			break;
		case 1:
			ok = createDoor(width - 1, (rand() % (height - 3)) + 2, map);
			break;
		case 2:
			ok = createDoor((rand() % (width - 3) + 2), height - 1, map);
			break;
		case 3:
			ok = createDoor(0, (rand() % (height - 3)) + 2, map);
			break;
		default:
			break;
		}
	}
}

bool RoomMapBuilder::createDoor(int column, int row, vector<vector<int>>* map) {
	if ((column == 0 || column == width - 1 || row == 0 || row == height - 1)
		&& !(column == row)
		&& !(column == 0 && row == height - 1)
		&& !(column == width - 1 && row == 0)) {
		(*map)[row][column]=id_door;
		return true;
	}
	return false;
}


void RoomMapBuilder::createEnemy(vector<vector<int>>* map, int id)
{
	Point point = getRandomInner(map);
	(*map)[point.getRow()][point.getColumn() ] = id+id_enemy_min;

}

void RoomMapBuilder::createHScale(vector<vector<int>>* map)
{
	Point point = getRandomInner(map);
	int size = (rand() % max((width - point.getColumn() - 15), 1)) + 1;
	for (int j = 0; j < size; j++) {
		if ((*map)[point.getRow() ][point.getColumn()+j] == id_inner
			&& (*map)[point.getRow() + 1][point.getColumn() + j] == id_inner)
			(*map)[point.getRow() ][point.getColumn()+j] = id_scale;
	}
}

void RoomMapBuilder::createVScale(vector<vector<int>>* map)
{
	Point point = getRandomInner(map);
	int size = (rand() % max((height - point.getRow() - 5), 1)) + 1;
	for (int j = 0; j < size; j++) {
		if ((*map)[point.getRow() + j][point.getColumn()]==id_inner
			&& (*map)[point.getRow() + j][point.getColumn()+1] == id_inner)
			(*map)[point.getRow() + j][point.getColumn()] =id_scale;
	}
}

void RoomMapBuilder::createTreasure(vector<vector<int>>* map)
{
	Point point = getRandomInner(map);
	for (int j = 0; j < treasureCount; j++) {
		(*map)[point.getRow()][point.getColumn()] = id_treasure;
		point = getRandomInner(map);
	}
}

Point RoomMapBuilder::getRandomInner(vector<vector<int>>* map)
{
	int i = 0;
	bool ok = false;
	int row, column;
	while (i < 40 && !ok) {
		row = (rand() % (height - 2)) + 1;
		column = (rand() % (width - 2)) + 1;
		ok = column>1 && column<width-2
			 && row>1 && row<height-2
			&& (*map)[row][column]==id_inner;
		i++;
	}
	return Point(column, row);
}