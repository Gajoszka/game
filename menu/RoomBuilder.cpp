#include "RoomBuilder.h"

Room RoomBuilder::build()
{

	createRoomMap();
	return Room(roomMap);
}


void RoomBuilder::createRoomMap() {
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
		createDoor();
	}

	for (int i = 0; i < this->obstacleCount; i++) {
		createHObstacle((rand() % (height - 4))+1, (rand() % (width - 4)) + 1, (rand() % (width - 25))+1);
		
	}
	for (int i = 0; i < this->obstacleCount; i++) {
		createVObstacle((rand() % (height - 4)) + 1, (rand() % (width - 4)) + 1 ,(rand() % (height - 5))+1);
		
	}


}


void RoomBuilder::createDoor() {
	int door;
	switch (rand()%4)
	{case 0:
		 door = rand() % width;
		roomMap[0][door] = -1;
		break;
	case 1:
		 door = rand() % height;
		roomMap[door][width-1] = -1;
		break;
	case 2:
		 door = rand() % width;
		roomMap[height-1][door] = -1;
		break;
	case 3:
	    door = rand() % height;
		roomMap[door][0] = -1;
		break;
	default:
		break;
	}

}

void RoomBuilder::createHObstacle(int x, int y, int size)
{
	for (int j = x; j < x+size; j++){
		if (roomMap[y][j] == 1)
			return;
			roomMap[y][j] = 2;
	}
}

void RoomBuilder::createVObstacle(int x, int y, int size)
{
	if (roomMap[y][x - 1] == -1)
		return;
	for (int j = y; j < y+size; j++){
		if (roomMap[j][x] == 1 || roomMap[j][x+1] == -1)
			return;
	roomMap[j][x] = 2;
}
}


