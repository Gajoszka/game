#pragma once
#include "Creature.h"
class Enemy : public Creature
{
public:
	Enemy() : Creature('E', 2, 1, 1) {};
};

