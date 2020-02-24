#include "RoomMapBuilder.h"
#include <stdlib.h>

std::vector<int> RoomMapBuilder::build()
{

	createRoomMap(roomMap);
	return *roomMap;
}


void RoomMapBuilder::createRoomMap(int roomMap[15][45]) {
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			roomMap[j][i] = 0;
		}
	}
	for (int i = 0; i < width; i++) {
		roomMap[0][i] = 1;
		roomMap[height-1][i] = 1;
	}

	for (int i = 0; i < height; i++) {
		roomMap[i][0] = 1;
		roomMap[i][width-1] = 1;
	}


	for (int i = 0; i < this->doorCount; i++) {
		createDoor(roomMap);
	}

	for (int i = 0; i < this->obstacleCount; i++) {
		createHObstacle(roomMap,(rand() % (height - 4))+1, (rand() % (width - 4)) + 1, (rand() % (width - 25))+1);
		
	}
	for (int i = 0; i < this->obstacleCount; i++) {
		createVObstacle(roomMap,(rand() % (height - 4)) + 1, (rand() % (width - 4)) + 1 ,(rand() % (height - 5))+1);
		
	}

	createTreasure(roomMap);
}


void RoomMapBuilder::createDoor(int roomMap[15][45]) {
	int door;
	switch (rand()%4)
	{case 0:
		 door = rand() % (width-2);
		roomMap[0][door+1] = -1;
		break;
	case 1:
		 door = rand() % (height-2);
		roomMap[door+1][width-1] = -1;
		break;
	case 2:
		 door = rand() % (width-2);
		roomMap[height-1][door+1] = -1;
		break;
	case 3:
	    door = rand() % (height-2);
		roomMap[door+1][0] = -1;
		break;
	default:
		break;
	}

}

void RoomMapBuilder::createHObstacle(int roomMap[15][45],int x, int y, int size)
{
	for (int j = x; j < x+size; j++){
		if (roomMap[y][j] == 1)
			return;
			roomMap[y][j] = 2;
	}
}

void RoomMapBuilder::createVObstacle(int roomMap[15][45],int x, int y, int size)
{
	if (roomMap[y][x - 1] == -1)
		return;
	for (int j = y; j < y+size; j++){
		if (roomMap[j][x] == 1 || roomMap[j][x+1] == -1)
			return;
	roomMap[j][x] = 2;
}
}


void RoomMapBuilder::createTreasure(int roomMap[15][45])
{
	for (int j = 0; j <  treasureCount; j++) {
		
		roomMap[(rand() % (height - 4)) + 2][(rand()%(width-5))+2] = 10;
	}
}

