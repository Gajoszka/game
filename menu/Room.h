#pragma once
#include "Frame.h"

class Room : public Frame
{
public:
	Room();
	virtual void printInside();
	virtual bool isInside(int x, int y);
	void generator();
private:
	char getSign(int x);
	int room[45][15];
	int widthRoom;
	int heightRoom;
};