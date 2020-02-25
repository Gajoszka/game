#include "Creature.h"
#include "Screen.h"

Creature::Creature(char sign, int hp, int attack, int defence): location(0, 0) {
	this->icon = sign;
	this->hp = hp;
	this->attack = attack;
	this->defence = defence;
};

void Creature::fight() {
};

void Creature::takeDamage() {
};

void Creature::clear() {
	gotoxy(location.getColumn(), location.getRow());
	cout << ' ';
}

void Creature::print(int x, int y)
{
	location.setColumn(x);
	location.setRow(y);
	gotoxy(location.getColumn(), location.getRow());
	cout << icon;
}
