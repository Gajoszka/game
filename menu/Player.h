#pragma once
#include <math.h>
#include "Dungeon.h"
class Player
{
public:
	const char user = '@';
	void playerSpace();
	int x;
	int y;
	void placeUser();
};

