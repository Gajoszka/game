#pragma once
/*Parent class for enemies and player, defining players' coordinates, how they fight, take damage */
#include "Point.h"
#include "RoomElement.h"

class Room;

class Creature : public  RoomElement
{
public:

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

