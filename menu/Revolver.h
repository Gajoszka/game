#pragma once
#include "Weapon.h"

class Revolver : public Weapon
{
	Revolver() : Weapon(id_gun_min + 2, 5, 15) {};
};

