#pragma once
#include "Frame.h"

class Room : public Frame
{
public:
	Room(int map[15][45]);
	virtual void printFrame();
	virtual void printInside();
	virtual bool isInside(int x, int y);
private:
	char getSign(int x);
	int arenaMap[15][45];
};