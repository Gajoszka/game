#pragma once
#include "Weapon.h"
#include "GameType.h"
#include "Creature.h"
/* Gun shooting and amunition interactions with creatures*/

class Gun :	public Weapon {
public:
	Gun() : Weapon(id_gun_min + 1, 2, 50) {};
	
};