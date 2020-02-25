#pragma once
#include "Stats.h"
#include "InfoDisplay.h"
#include "MainFrame.h"
class GameLayout
{
public:
	GameLayout() : mainFrame(), statsFrame(20,10), infoFrame(48,5) ,mapFrame(10,10),activeItemFrame(9,10){
		shutCursor(false);
		setFont();
		mapFrame.print(50, 1);
		activeItemFrame.print(61, 1);
		statsFrame.print(50, 15);
		infoFrame.print(1, 20);
		mainFrame.print(1, 1);
		infoFrame.printLine(4, "F5-new room, F10-exit");
	};
	void printScore(int score) {
		statsFrame.printLine(2, "Score: " + std::to_string(score));
	}
	void printName(std::string name) {
		statsFrame.printLine(1, "Player: " + name);

	}
	void printInfo(std::string value) {
		infoFrame.printLine(1, value);

	}

	void printRoom(vector<vector<RoomElement>> roomMap) {
		(*getRoom()).setMap(roomMap);
		mainFrame.printInside();
	}
	void setRoom(Room *room){}
	Room* getRoom() {
		return mainFrame.getRoom();
	}
	~GameLayout();
private:
	MainFrame mainFrame;
	InfoDisplay statsFrame;
	InfoDisplay infoFrame;
	InfoDisplay mapFrame;
	InfoDisplay activeItemFrame;
	void setFont();
	void shutCursor(bool visible);
};

