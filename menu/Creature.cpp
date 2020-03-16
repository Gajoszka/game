#include "Creature.h"
#include "Screen.h"

void Creature::fight() {
};

void Creature::takeDamage() {
};

void Creature::setLocation(int column, int row) {
	location.setColumn(column);
	location.setRow(row);
};

void Creature::setLocation(Point l) {
	location = l;
};

