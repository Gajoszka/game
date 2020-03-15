#include "Room.h"
#include "Screen.h"
#include "Enemy.h"
#include "RoomElementFactory.h"


Room::Room(int width, int height, RoomElementFactory* elementFactory) {
	last_move_enemy_time = clock() / CLOCKS_PER_SEC;
	this->width = width;
	this->height = height;
	this->elementFactory = elementFactory;
	for (int row = 0; row < height; row++) {
		vector<RoomElement*> tmp;
		for (int i = 0; i < width; i++) {
			tmp.push_back(elementFactory->getInner());
		}
		roomMap.push_back(move(tmp));
	}
}

RoomElement* Room::get(int column, int row) {
	if (row >= 0 && row < height && column >= 0 && column < width) {
		return roomMap[row][column];
	}
	return nullptr;
}

Room::~Room()
{
	for (vector<RoomElement*> vector : roomMap) {
		vector.clear();
	}
	roomMap.clear();
}

bool  Room::put(int column, int row, RoomElement* el) {
	if (row >= 0 && row < height && column >= 0 && column < width) {
		roomMap[row][column] = el;
		if (printer != nullptr)
			printer(column, row, (*el).icon);
		if (Creature* t = dynamic_cast<Creature*>(el))
			(*(Creature*)el).setLocation(column, row);
		return true;
	}
	return false;
}

bool  Room::putInInner(RoomElement* el) {
	Point point = getRandomInner();
	return put(point.getColumn(), point.getRow(), el);
}


// time between enemies moves
void Room::moveEnemys() {
	if (clock() / CLOCKS_PER_SEC - last_move_enemy_time < 1) // for enemies not to move to fast, every 0.3s
		return;
	last_move_enemy_time = clock() / CLOCKS_PER_SEC;
	// chooses only one enemy to move
	elementFactory->getRandEnemy()->move();
	elementFactory->getRandEnemy()->shot();
}

GameAction Room::moveCreature(int column, int row, int _delay, Creature* el) {
	RoomElement* actEl = get(column, row);
	put(el->getLocation().getColumn(), el->getLocation().getRow(), elementFactory->getInner());
	delay(_delay);
	put(column, row, el);
	return served;
}

bool Room::isInner(int column, int row) {
	if ( column<1 || row<1 
		|| roomMap[row][column - 1]->id == id_door
		|| roomMap[row][column]->id == id_door
		|| roomMap[row][column + 1]->id == id_door
		|| roomMap[row - 1][column]->id == id_door)
		return false;
	if (roomMap[row - 1][column]->id != id_inner && roomMap[row + 1][column]->id != id_inner)
		return false;
	return true;

	/*bool Room::canPut(int column, int row) {
		return get(column, row).canPass;
	}*/
}

Point Room::getRandomInner()
{
	int i = 0;
	bool ok = false;
	int row, column;
	while (i < 40 && !ok) {
		row = (rand() % (height - 2)) + 1;
		column = (rand() % (width - 2)) + 1;
		ok = isInner(column, row);
		i++;
	}
	return Point(column, row);
}

GameAction Room::runAction(GameAction action)
{
	moveEnemys();
	return action;
}



