#pragma once
#include "Room.h"
class RoomBuilder
{
public:
	RoomBuilder() {

	}
	Room build();
	void setWallCount(int count){
		this->wallCount = count;	
	}
	
private:
	int wallCount = 0;
	int doorCount = 1;
	int width = 45;
	int rows[15][45];
	int height = 15;
	void generator();
};

