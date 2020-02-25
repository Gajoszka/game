#pragma once
#include "Point.h"
#include "RoomElement.h"

class Creature : public  RoomElement
{
public:
	//Creature() {};

	virtual void fight();
	virtual void takeDamage();
	Point getRoomLocation() {
		return roomLocation;
	};

	void setLocation(Point l) {
		roomLocation = l;
	};

	void setRoomLocation(int column, int row) {
		roomLocation.setColumn(column);
		roomLocation.setRow(row);
	};
protected:
	Creature(int id, char sign, int hp, int attack, int defence) : RoomElement(id, sign, true, 0), roomLocation(0, 0) {
		this->hp = hp;
		this->attack = attack;
		this->defence = defence;
	};
private:
	int hp;
	int attack;
	int defence;
	Point roomLocation;
};

