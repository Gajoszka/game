#include "Creature.h"


Creature::Creature(char sign, int hp, int attack, int defence) {
	this->sign = sign;
	this->hp = hp;
	this->attack = attack;
	this->defence = defence;
};

void Creature::fight() {
};

void Creature::takeDamage() {
};