#pragma once
#include "Player.h"
class KeyFunctions
{
public:
	void connection();
	void movement();
	void clear();
	Player obj;
	int x = obj.x;
	int y = obj.y;
	bool inp = true;
};

