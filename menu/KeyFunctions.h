#pragma once
#include "Player.h"
class KeyFunctions
{
public:
	void connection();
	void movement();
	void clear();
	Player obj;
	int x = obj.getLocation().getX();
	int y = obj.getLocation().getY();
	bool inp = true;
};

