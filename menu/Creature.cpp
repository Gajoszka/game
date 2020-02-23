#include "Creature.h"


Creature::Creature(char sign, int hp, int attack, int defence) {
	this->sign = sign;
	this->hp = hp;
	this->attack = attack;
	this->defence = defence;
};

bool Creature::playerGoTo(int x, int y)
{
	return false;
}

void Creature::fight() {
};

void Creature::takeDamage() {
};