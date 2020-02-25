#pragma once
#include "Player.h"
class KeyFunctions
{
public:
	void connection();
	void movement();
	void clear();
	Player obj;
	int x = obj.getRoomLocation().getColumn();
	int y = obj.getRoomLocation().getRow();
	bool inp = true;
};

