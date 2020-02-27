#include "Creature.h"
#include "Screen.h"
#include "RoomElement.h"

void Creature::fight() {
};

void Creature::takeDamage() {
};

void Creature::setLocation(int column, int row) {
	roomLocation.setColumn(column);
	roomLocation.setRow(row);
};

void Creature::setLocation(Point l) {
	roomLocation = l;
};
