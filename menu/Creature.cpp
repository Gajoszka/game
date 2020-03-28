#include "Creature.h"
#include "Screen.h"
/*Parent class for enemies and player, defining players' coordinates, how they fight, take damage */

void Creature::takeDamage() {
};

void Creature::setLocation(int column, int row) {
	location.setColumn(column);
	location.setRow(row);
};

void Creature::setLocation(Point l) {
	location = l;
};

