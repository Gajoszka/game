#pragma once
/*Parent class for enemies and player, child class of Room Element */
#include "Point.h"
#include "RoomElement.h"
//#include "Room.h"

class Room;

class Creature : public  RoomElement
{
public:
	//Creature() {};

	virtual void fight();
	virtual void takeDamage();
	Point getLocation() {
		return location;
	};

	void setLocation(Point l);

	void setLocation(int column, int row);
	Point lastMoveDirection;
protected:
	// constructor with parameters id, name, health points, attack and damage, mapping creature as an element of the room
	Creature(int id, char sign, int hp, int attack, int defence) : RoomElement(id, sign, true), location(0, 0), lastMoveDirection(1,0){
		this->hp = hp;
		this->attack = attack;
		this->defence = defence;
	}
	Point location;

private:
	int hp;
	int attack;
	int defence;


};

