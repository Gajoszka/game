#pragma once
#include "Frame.h"
#include "Room.h"
class MainFrame :
	public Frame
{
public:
	MainFrame() : Frame(48, 18) ,room(){
	}
	virtual void printInside();
	void setRoom(Room _room) {
		room = _room;
	}
	Room* getRoom() {
		return &room;
	}
private:
	Room room;

};

