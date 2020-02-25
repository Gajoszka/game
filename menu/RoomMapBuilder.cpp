#include "RoomMapBuilder.h"
#include <windows.h>
#include <stdio.h>


std::vector<std::vector<RoomElement>> RoomMapBuilder::build()
{
	vector<vector<RoomElement>> roomMap;
	for (int row = 0; row < height; row++) {
		vector<RoomElement> tmp;
		for (int i = 0; i < width; i++) {
			tmp.push_back(room_inner);
		}
		roomMap.push_back(move(tmp));
	}

	//horizontal wall
	for (int column = 0; column < width; column++) {
		roomMap[0][column] = room_wall;
		roomMap[height - 1][column] = room_wall;
	}
	//vertical wall
	for (int row = 0; row < height; row++) {
		roomMap[row][0] = room_wall;
		roomMap[row][width - 1] = room_wall;
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


void RoomMapBuilder::createDoor(std::vector<std::vector<RoomElement>>* tmpRows) {
	int door;
	switch (rand() % 4)  //witch wall
	{
	case 0:
		door = rand() % (width - 2);
		(*tmpRows)[0][door + 1] = room_door;
		break;
	case 1:
		door = rand() % (height - 2);
		(*tmpRows)[door + 1][width - 1] = room_door;
		break;
	case 2:
		door = rand() % (width - 2);
		(*tmpRows)[height - 1][door + 1] = room_door;
		break;
	case 3:
		door = rand() % (height - 2);
		(*tmpRows)[door + 1][0] = room_door;
		break;
	default:
		break;
	}

}

void RoomMapBuilder::createHObstacle(std::vector<std::vector<RoomElement>>* tmpRows)
{
	int column = (rand() % (width - 5)) + 1;
	int row = (rand() % (height - 4)) + 1;
	int size = (rand() % max((width - column - 15), 1)) + 1;
	for (int j = column; j < column + size; j++) {
		if (canObstalace(tmpRows, row, j))
			//return;
		(*tmpRows)[row][j] = room_obstacle;
	}
}

void RoomMapBuilder::createVObstacle(std::vector<std::vector<RoomElement>>* tmpRows)
{
	int column = (rand() % (width - 3)) + 1;
	int row = (rand() % (height - 4)) + 1;
	int size = (rand() % max((height - row - 5), 1)) + 1;

	for (int j = row; j < row + size; j++) {
		if (canObstalace(tmpRows, j, column))
			//return;
		(*tmpRows)[j][column] = room_obstacle;
	}
}

bool RoomMapBuilder::canObstalace(vector<vector<RoomElement>>* tmpRows, int row, int column) {
	if ((*tmpRows)[row][column - 1].id == room_door.id 
		|| (*tmpRows)[row][column].id == room_wall.id 
		|| (*tmpRows)[row][column + 1].id == room_door.id)
		return false;
	if ((*tmpRows)[row - 1][column].id != room_inner.id && (*tmpRows)[row + 1][column].id != room_inner.id)
		return false;
	return true;
}

void RoomMapBuilder::createTreasure(std::vector<std::vector<RoomElement>>* tmpRows)
{
	for (int j = 0; j < treasureCount; j++) {
		(*tmpRows)[(rand() % (height - 4)) + 2][(rand() % (width - 5)) + 2] = room_treasure;
	}
}

