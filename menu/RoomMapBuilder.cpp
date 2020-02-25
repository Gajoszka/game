#include "RoomMapBuilder.h"
#include <windows.h>
#include <stdio.h>


std::vector<std::vector<int>> RoomMapBuilder::build()
{
	vector<vector<int>> roomMap;
	for (int row = 0; row < height; row++) {
		vector<int> tmp;
		for (int i = 0; i < width; i++) {
			tmp.push_back(0);
		}
		roomMap.push_back(move(tmp));
	}

	//horizontal wall
	for (int column = 0; column < width; column++) {
		roomMap[0][column] = 1;
		roomMap[height - 1][column] = 1;
	}
	//vertical wall
	for (int row = 0; row < height; row++) {
		roomMap[row][0] = 1;
		roomMap[row][width - 1] = 1;
	}


	for (int i = 0; i < this->doorCount; i++) {
		createDoor(&roomMap);
	}

	for (int i = 0; i < this->obstacleCount-1; i++) {
		createHObstacle(&roomMap);

	}
	for (int i = 0; i < this->obstacleCount; i++) {
		createVObstacle(&roomMap);

	}

	createTreasure(&roomMap);
	return roomMap;
}


void RoomMapBuilder::createDoor(std::vector<std::vector<int>>* tmpRows) {
	int door;
	switch (rand() % 4)  //witch wall
	{
	case 0:
		door = rand() % (width - 2);
		(*tmpRows)[0][door + 1] = -1;
		break;
	case 1:
		door = rand() % (height - 2);
		(*tmpRows)[door + 1][width - 1] = -1;
		break;
	case 2:
		door = rand() % (width - 2);
		(*tmpRows)[height - 1][door + 1] = -1;
		break;
	case 3:
		door = rand() % (height - 2);
		(*tmpRows)[door + 1][0] = -1;
		break;
	default:
		break;
	}

}

void RoomMapBuilder::createHObstacle(std::vector<std::vector<int>>* tmpRows)
{
	int column = (rand() % (width - 5)) + 1;
	int row = (rand() % (height - 4)) + 1;
	int size = (rand() % max((width - column - 15), 1)) + 1;
	for (int j = column; j < column + size; j++) {
		if (!canObstalace(tmpRows, row, j))
			return;
		(*tmpRows)[row][j] = 2;
	}
}

void RoomMapBuilder::createVObstacle(std::vector<std::vector<int>>* tmpRows)
{
	int column = (rand() % (width - 3)) + 1;
	int row = (rand() % (height - 4)) + 1;
	int size = (rand() % max((height - row - 5), 1)) + 1;

	for (int j = row; j < row + size; j++) {
		if (!canObstalace(tmpRows, j, column))
			return;
		(*tmpRows)[j][column] = 2;
	}
}

bool RoomMapBuilder::canObstalace(vector<vector<int>>* tmpRows, int row, int column) {
	if ((*tmpRows)[row][column - 1] == -1 || (*tmpRows)[row][column] == 1 || (*tmpRows)[row][column + 1] == -1)
		return false;
	if ((*tmpRows)[row - 1][column] != 0 && (*tmpRows)[row + 1][column] != 0)
		return false;
	return true;
}

void RoomMapBuilder::createTreasure(std::vector<std::vector<int>>* tmpRows)
{
	for (int j = 0; j < treasureCount; j++) {
		(*tmpRows)[(rand() % (height - 4)) + 2][(rand() % (width - 5)) + 2] = 10;
	}
}

