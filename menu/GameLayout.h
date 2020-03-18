#pragma once
/* Creating game layout, creating frames in desired places
and controlling their inputs*/
#include "InfoFrame.h"
#include "RoomFrame.h"
#include "GameDef.h"
#include <string>
using namespace std;

class GameLayout
{
public:
	// setting sizes of individual frames
	GameLayout() : roomFrame(48, 18), statsFrame(20, 10), infoFrame(48, 5), mapFrame(10, 10), activeItemFrame(9, 10) {
		shutCursor(false);
		setFont();
		mapFrame.print(50, 1); // coordinates where printing begins
		activeItemFrame.print(61, 1);
		statsFrame.print(50, 15);
		infoFrame.print(1, 20);
		roomFrame.print(1, 1);
		infoFrame.printCenterLine(4, "space-fire, F3-new room, F4- buy, F10-exit");
	};
	void printName(string name);
	void printInfo(string value);

	void setRoom(Room* room);
	void print(messageType type, string msg);
	void shutCursor(bool visible);
	RoomFrame* getRoomFrame() {
		return &roomFrame;
	}
	~GameLayout();
private:
	RoomFrame roomFrame;
	InfoFrame statsFrame;
	InfoFrame infoFrame;
	InfoFrame mapFrame;
	InfoFrame activeItemFrame;
	void setFont();
	
	
};

