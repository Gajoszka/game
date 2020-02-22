#pragma once
#include "Frame.h"

class Room : public Frame
{
public:
	Room();
	virtual void printInside();
private:
	int room[45][15] = ;
};