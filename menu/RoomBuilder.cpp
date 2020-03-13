#include "RoomBuilder.h"
#include <windows.h>
#include <stdio.h>
#include "Enemy.h"

RoomBuilder::RoomBuilder(int width, int heihgt) {
	this->width = width;
	this->height = height;
}

void RoomBuilder::setScaleCount(int count) {
	this->scaleCount = count <= 0 ? 0 : count; // like if statement, right after ? if true, after if false
}
void RoomBuilder::setDoorCount(int count) {
	this->doorCount = count <= 0 ? 1 : count;
}
void RoomBuilder::setTreasureCount(int count) {
	this->treasureCount = count <= 0 ? 0 : count;
}
void RoomBuilder::setEnemyCount(int count) {
	this->enemyCount = count <= 0 ? 0 : count;
}
Room RoomBuilder::build()
{
	Room room(width, height);

	//horizontal wall
	for (int column = 0; column < width; column++) {
		room.setWall(column, 0);
		room.setWall(column, height - 1);
	}
	//vertical wall
	for (int row = 0; row < height; row++) {
		room.setWall(0, row);
		room.setWall(width - 1, row);
	}

	for (int i = 0; i < this->doorCount; i++) {
		createDoor(&room);
	}

	for (int i = 0; i < this->scaleCount - 5; i++) {
		createHInnerWall(&room);

	}
	for (int i = 0; i < this->scaleCount; i++) {
		createVInnerWall(&room);
	}

	for (int i = 0; i < this->enemyCount; i++) {
		createEnemy(&room,  i);
	}

	createTreasure(&room);
	return room;
}


void RoomBuilder::createDoor(Room* room) {

	bool ok = false;
	while (!ok) {
		switch (rand() % 4)  //which wall
		{
		case 0:
			ok = (*room).setDoor( (rand() % (width - 3)) + 2,0);
			break;
		case 1:
			ok = (*room).setDoor(width - 1,(rand() % (height - 3)) + 2);
			break;
		case 2:
			ok = (*room).setDoor( (rand() % (width - 3) + 2), height - 1);
			break;
		case 3:
			ok = (*room).setDoor(0,(rand() % (height - 3)) + 2);
			break;
		default:
			break;
		}
	}
}

void RoomBuilder::createEnemy(Room* room, int id)
{
	Enemy enemy(id);
	int i = 0;
	while (i < 10 && !(*room).setEnemy((rand() % (width - 2)) + 1, (rand() % (height - 2)) + 1, enemy))
		i++;
}

void RoomBuilder::createHInnerWall(Room* room)
{
	int column = (rand() % (width - 5)) + 1;
	int row = (rand() % (height - 4)) + 1;
	int size = (rand() % max((width - column - 15), 1)) + 1;
	for (int j = column; j < column + size; j++) {
		(*room).setScale(j, row);
	}
}

void RoomBuilder::createVInnerWall(Room* room)
{
	int column = (rand() % (width - 3)) + 1;
	int row = (rand() % (height - 4)) + 1;
	int size = (rand() % max((height - row - 5), 1)) + 1;
	for (int j = row; j < row + size; j++) {
		(*room).setScale(column, j);
	}
}


void RoomBuilder::createTreasure(Room* room)
{
	for (int j = 0; j < treasureCount; j++) {
		(*room).setTreasure((rand() % (width - 5)) + 2, (rand() % (height - 4)) + 2);
	}
}

