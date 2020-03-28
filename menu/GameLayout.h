#pragma once
/*Displaying current information and room*/
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
	
	};
	void printLayout();
	void printName(string name);
	void printInfo(string value);
	void refresh();
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