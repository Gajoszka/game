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
Room* RoomBuilder::build(RoomElementFactory* elementFactory)
{
	Room* room = new Room(width, height, elementFactory);
	//horizontal wall
	for (int column = 0; column < width; column++) {
		(*room).put(column, 0, (*elementFactory).getWall());
		(*room).put(column, height - 1, (*elementFactory).getWall());
	}
	//vertical wall
	for (int row = 0; row < height; row++) {
		(*room).put(0, row, (*elementFactory).getWall());
		(*room).put(width - 1, row, (*elementFactory).getWall());
	}

	for (int i = 0; i < this->doorCount; i++) {
		createDoor(room, elementFactory);
	}

	for (int i = 0; i < this->scaleCount ; i++) {
		createHScale(room, elementFactory);

	}
	for (int i = 0; i < this->scaleCount-1; i++) {
		createVScale(room, elementFactory);
	}

	for (int i = 0; i < this->enemyCount; i++) {
		createEnemy(room, elementFactory, i);
	}
	createTreasure(room, elementFactory);
	return room;
}

void RoomBuilder::createDoor(Room* room, RoomElementFactory* elementFactory) {

	bool ok = false;
	while (!ok) {
		switch (rand() % 4)  //which wall
		{
		case 0:
			ok = createDoor(rand() % (width - 3) + 2, 0, room, elementFactory);
			break;
		case 1:
			ok = createDoor(width - 1, (rand() % (height - 3)) + 2, room, elementFactory);
			break;
		case 2:
			ok = createDoor((rand() % (width - 3) + 2), height - 1, room, elementFactory);
			break;
		case 3:
			ok = createDoor(0, (rand() % (height - 3)) + 2, room, elementFactory);
			break;
		default:
			break;
		}
	}
}

bool RoomBuilder::createDoor(int column, int row, Room* room, RoomElementFactory* elementFactory) {
	if ((column == 0 || column == width - 1 || row == 0 || row == height - 1)
		&& !(column == row)
		&& !(column == 0 && row == height - 1)
		&& !(column == width - 1 && row == 0)) {
		(*room).put(column, row, (*elementFactory).getDoor());
		return true;
	}
	return false;
}


void RoomBuilder::createEnemy(Room* room, RoomElementFactory* elementFactory, int id)
{
	Enemy* enemy = (*elementFactory).getEnemy(id);
	(*enemy).setRoom(room);
	(*room).putInInner(enemy);
}

void RoomBuilder::createHScale(Room* room, RoomElementFactory* elementFactory)
{
	Point point = (*room).getRandomInner();
	int size = (rand() % max((width - point.getColumn() - 15), 1)) + 1;
	for (int j = 0; j < size; j++) {
		if ((*room).isInner(point.getColumn() + j, point.getRow())
			&& room->get(point.getColumn() +j, point.getRow() + 1)->id == id_inner)
			(*room).put(point.getColumn() + j, point.getRow(), (*elementFactory).getScale());
	}
}

void RoomBuilder::createVScale(Room* room, RoomElementFactory* elementFactory)
{
	Point point = (*room).getRandomInner();
	int size = (rand() % max((height - point.getRow() - 5), 1)) + 1;
	for (int j = 0; j < size; j++) {
		if ((*room).isInner(point.getColumn(), point.getRow()+j)
			&& room->get(point.getColumn()+1,point.getRow() + j)->id==id_inner)
			(*room).put(point.getColumn() , point.getRow()+j, (*elementFactory).getScale());
	}
}

void RoomBuilder::createTreasure(Room* room, RoomElementFactory* elementFactory)
{
	for (int j = 0; j < treasureCount; j++) {
		(*room).putInInner((*elementFactory).getTreasure());
	}
}

