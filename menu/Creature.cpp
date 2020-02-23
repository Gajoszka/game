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
	gotoxy(location.getX(), location.getY());
	cout << ' ';
}

void Creature::print(int x, int y)
{
	location.setX(x);
	location.setY(y);
	gotoxy(location.getX(), location.getY());
	cout << icon;
}
