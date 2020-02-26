#pragma once
#include "Player.h"
class KeyFunctions
{
public:
	void connection();
	void movement();
	void clear();
	Player obj;
	int x = obj.getLocation().getColumn();
	int y = obj.getLocation().getRow();
	bool inp = true;
};

