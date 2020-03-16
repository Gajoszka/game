#pragma once
#include <xiosbase>
#include <vector>
#include "RoomElement.h"
#include "GameDef.h"
#include "GameType.h"
#include <ctime>
#include "Point.h"
//#include "Creature.h"
//#include "RoomElementFactory.h"


using namespace std;

class RoomElementFactory;
class Creature;


class Room {
public:
	Room(int width, int height, RoomElementFactory* elementFactory);
	void setPrinter(printElement printer) { //following the point on the screen
		this->printer = printer;
	}
	void setPrinterMessage(printMessage printer) { //displaying info in specified place
		this->printerMsg = printer;
	}
	bool put(int column, int row, RoomElement* el);
	bool putInInner(RoomElement* el);
	RoomElement* get(int column, int row);
	void moveEnemys();

	bool isInner(int column, int row);
	
	GameAction runAction(GameAction action);
	GameAction moveCreature(int column, int row,int delay, Creature* el);
	void boomSimulation(Creature* creature, bool death);

	char getIcon(int column, int row) {
		return (*get(column, row)).icon;
	}

	int getId(int column, int row) {
		return (*get(column, row)).id;
	}

	int getWidth() {
		return width;
	}

	int getHeight() {
		return height;
	}

	RoomElementFactory* getElementFactory() {
		return elementFactory;
	}
	
	Point getRandomInner();
	~Room();
	printElement printer = nullptr;
	printMessage printerMsg = nullptr;
private:
	int width;
	int height;
	RoomElementFactory* elementFactory;
	vector<vector<RoomElement*>> roomMap; //2d vector
	clock_t last_move_enemy_time;
	
};



