#include "RoomMapBuilder.h"
#include <windows.h>
#include <stdio.h>
#include "Enemy.h"





RoomMap RoomMapBuilder::build()
{
	RoomMap roomMap(width, height);


	//horizontal wall
	for (int column = 0; column < width; column++) {
		roomMap.setWall(0, column);
		roomMap.setWall(height - 1, column);
	}
	//vertical wall
	for (int row = 0; row < height; row++) {
		roomMap.setWall(row, 0);
		roomMap.setWall(row, width - 1);
	}


	for (int i = 0; i < this->doorCount; i++) {
		createDoor(roomMap);
	}

	for (int i = 0; i < this->obstacleCount - 1; i++) {
		createHInnerWall(&roomMap);

	}
	for (int i = 0; i < this->obstacleCount; i++) {
		createVInnerWall(roomMap);
	}

	for (int i = 0; i < this->enemyCount; i++) {
		createEnemy(roomMap, 101 + i);
	}

	createTreasure(roomMap);
	return roomMap;
}


void RoomMapBuilder::createDoor(RoomMap roomMap) {

	switch (rand() % 4)  //witch wall
	{
	case 0:
		roomMap.setDoor(0, (rand() % (width - 3)) + 2);
		break;
	case 1:
		roomMap.setDoor((rand() % (height - 3)) + 2, width - 1);
		break;
	case 2:
		roomMap.setDoor(height - 1, (rand() % (width - 3) + 2));
		break;
	case 3:
		roomMap.setDoor((rand() % (height - 3)) + 2, 0);
		break;
	default:
		break;
	}
}

void RoomMapBuilder::createEnemy(RoomMap roomMap, int id)
{
	Enemy enemy(id);
	int i = 0;
	while (i < 10 && !roomMap.setEnemy((rand() % (width - 2)) + 1, (rand() % (height - 2)) + 1, &enemy))
	i++;
}


void RoomMapBuilder::createHInnerWall(RoomMap* roomMap)
{
	int column = (rand() % (width - 5)) + 1;
	int row = (rand() % (height - 4)) + 1;
	int size = (rand() % max((width - column - 15), 1)) + 1;
	for (int j = column; j < column + size; j++) {
		(*roomMap).setScale(j,row);
	}
}

void RoomMapBuilder::createVInnerWall(RoomMap roomMap)
{
	int column = (rand() % (width - 3)) + 1;
	int row = (rand() % (height - 4)) + 1;
	int size = (rand() % max((height - row - 5), 1)) + 1;
	for (int j = row; j < row + size; j++) {
		roomMap.setScale(column,j);
	}
}



void RoomMapBuilder::createTreasure(RoomMap roomMap)
{
	for (int j = 0; j < treasureCount; j++) {
		roomMap.setTreacure((rand() % (width - 5)) + 2,(rand() % (height - 4)) + 2);
	}
}

