#pragma once
#include "Floor.h"

class FloorBuilder {
public:
	FloorBuilder();

	Floor* build();
	void setRoomCount(int count) {
		roomCount = count;
	}

private:
	int roomCount = 0;
};


