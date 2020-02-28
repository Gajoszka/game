#pragma once
/* Creating game layout, creating frames in desired places
and controlling their inputs*/
#include "Stats.h"
#include "InfoDisplay.h"
#include "RoomFrame.h"
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
		infoFrame.printLine(4, "F5-new room, F10-exit");
	};
	void printScore(int score);
	void printName(string name);
	void printInfo(string value);
	void printRoom(Room room);
	
	RoomFrame* getRoomFrame() {
		return &roomFrame;
	}
	~GameLayout();
private:
	RoomFrame roomFrame;
	InfoDisplay statsFrame;
	InfoDisplay infoFrame;
	InfoDisplay mapFrame;
	InfoDisplay activeItemFrame;
	void setFont();
	void shutCursor(bool visible);
	
};

