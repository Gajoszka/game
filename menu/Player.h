#pragma once
#include <math.h>
#include "Dungeon.h"
class Player
{
public:
	char player = '@';
	void playerSpace();
	void movement();
	void clear();
	bool inp = true;
	int x;
	int y;
	void placeUser();
};

