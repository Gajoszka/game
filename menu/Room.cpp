#include "Room.h"
#include "Screen.h"
#include "Enemy.h"
#include "RoomElementFactory.h"
#include "Creature.h"
/*Room creation*/

Room::Room(vector<vector<int>> map, RoomElementFactory* elementFactory)
{
	this->pElementFactory = elementFactory;
	setMap(map);
}

// inserting map elements
void Room::setMap(vector<vector<int>> map)
{
	mapId = map;
	height = map.size();
	width = map[0].size();
	RoomElement* el;
	for (int row = 0; row < height; row++) {
		vector<RoomElement*> tmp;
		for (int column = 0; column < width; column++) {
			el = pElementFactory->get(map[row][column]);
			if (Creature* creature = dynamic_cast<Creature*>(el))
				creature->setLocation(column,row);
			if (Enemy* enemy = dynamic_cast<Enemy*>(el))
				enemy->setRoom(this);
			tmp.push_back(el);
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

// destructor
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
		if (Creature* creature = dynamic_cast<Creature*>(el))
			creature->setLocation(column, row);
		return true;
	}
	return false;
}

// making position of elements random
bool  Room::putInInner(RoomElement* el) {
	Point point = getRandomInner();
	return put(point.getColumn(), point.getRow(), el);
}

// checking if element can be stepped into
bool Room::canMove(int column, int row,RoomElement* el) {
	RoomElement* actEl = get(column, row);
	if (actEl == nullptr
		|| !actEl->canPass
		|| actEl->id == id_door
		|| actEl->id == id_treasure
		|| actEl->id >= id_enemy_min)
		return false;
	return true;
}

// time between enemies moves
GameAction Room::moveEnemys() {
	if (clock() / CLOCKS_PER_SEC - last_move_enemy_time < 1) // for enemies not to move to fast, every 0.3s
		return served;
	GameAction action=served;
	last_move_enemy_time = clock() / CLOCKS_PER_SEC;
	// chooses only one enemy to move
	Enemy* enemy;
	if ((enemy = pElementFactory->getRandEnemy()) != nullptr)
		action=enemy->move();
	if (action == served && (enemy = pElementFactory->getRandEnemy()) != nullptr)
		action = enemy->shot();
	if (action==served && (enemy = pElementFactory->getRandEnemy()) != nullptr)
		action = enemy->shot();
	return action;
}

// making movement move real (dissapear and delay)
GameAction Room::moveSimulation(int column, int row, int _delay, Creature* el) {
	RoomElement* actEl = get(column, row);
	put(el->getLocation().getColumn(), el->getLocation().getRow(), pElementFactory->getInner());
	delay(_delay);
	put(column, row, el);
	return served;
}

// making simulation look more realistic
void Room::boomSimulation(Creature* creature, bool death)
{
	printerMsg(messageType::info, "BOOM!!");
	// sign in all neighbour coordinates
	for (int i = 1; i < 3; i++) {
		RoomElement* actEl0 = get(creature->getLocation().getColumn() + 1, creature->getLocation().getRow());
		if (actEl0->canPass) {
			printer(creature->getLocation().getColumn() + 1, creature->getLocation().getRow(), '.');
		}
		delay(10);
		RoomElement* actEl1 = get(creature->getLocation().getColumn() - 1, creature->getLocation().getRow());
		if (actEl1->canPass) {
			printer(creature->getLocation().getColumn() - 1, creature->getLocation().getRow(), '.');
			delay(10);
		}
		RoomElement* actEl2 = get(creature->getLocation().getColumn(), creature->getLocation().getRow() + 1);
		if (actEl2->canPass) {
			printer(creature->getLocation().getColumn(), creature->getLocation().getRow() + 1, '.');
			delay(10);
		}
		RoomElement* actEl3 = get(creature->getLocation().getColumn(), creature->getLocation().getRow() - 1);
		if (actEl3->canPass) {
			printer(creature->getLocation().getColumn(), creature->getLocation().getRow() - 1, '.');
		}
		delay(50);
		printer(creature->getLocation().getColumn() + 1, creature->getLocation().getRow(), actEl0->icon);
		delay(10);
		printer(creature->getLocation().getColumn() - 1, creature->getLocation().getRow(), actEl1->icon);
		delay(10);
		printer(creature->getLocation().getColumn(), creature->getLocation().getRow() + 1, actEl2->icon);
		delay(10);
		printer(creature->getLocation().getColumn(), creature->getLocation().getRow() - 1, actEl3->icon);
		delay(30);
	}
	// dead enemy disappearance
	if (death) {
		put(creature->getLocation().getColumn(), creature->getLocation().getRow(), pElementFactory->getInner());
		if (Enemy* enemy = dynamic_cast<Enemy*>(creature)) {
			pElementFactory->removeEnemy(enemy);
		}
	}
	else
		printer(creature->getLocation().getColumn(), creature->getLocation().getRow(), creature->icon);
	printerMsg(messageType::info, "");
}


bool Room::isInner(int column, int row) {
	if (column < 1 || row < 1
		|| roomMap[row][column - 1]->id == id_door
		|| roomMap[row][column]->id == id_door
		|| roomMap[row][column + 1]->id == id_door
		|| roomMap[row - 1][column]->id == id_door)
		return false;
	if (roomMap[row - 1][column]->id != id_inner && roomMap[row + 1][column]->id != id_inner)
		return false;
	return true;
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
	return moveEnemys();
}