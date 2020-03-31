#include "GameLayout.h"
#include "Screen.h"
#include <string>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
/*Displaying current information and room*/
using namespace std;

//setting font size and style
void GameLayout::setFont() {
	//_setmode(_fileno(stdout), _O_U16TEXT);
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX cfi;

	CONSOLE_FONT_INFOEX Font = { sizeof(Font) };
	GetCurrentConsoleFontEx(hStdout, FALSE, &Font);

	cfi.cbSize = sizeof cfi;
	cfi.nFont = 8;
	cfi.dwFontSize.X = 10;
	cfi.dwFontSize.Y = 16;
	cfi.FontFamily = FF_ROMAN;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Consolas");

}

// cursor disappearance
void GameLayout::shutCursor(bool visible) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ccur;
	ccur.dwSize = sizeof(CONSOLE_CURSOR_INFO);
	ccur.bVisible = visible;
	SetConsoleCursorInfo(hStdOut, &ccur);
}

// destructor - cursor appearance
GameLayout::~GameLayout() {
}


void GameLayout::printLayout()
{
	mapFrame.print(50, 1, "Map"); // coordinates where printing begins
	activeItemFrame.print(61, 1, "");
	statsFrame.print(50, 15, "Stats");
	infoFrame.print(1, 20, "Info");
	roomFrame.print(1, 1, "Room");
	infoFrame.printCenterLine(4, "space-fire,F1-shop, F3-new room, F10-exit");
}

// displays players username
void GameLayout::printName(string name) {
	statsFrame.addContent(1, "Player: " + name);
}

// displays additional information
void GameLayout::printInfo(string value) {
	infoFrame.printCenterLine(1, value);
}

void GameLayout::refresh()
{
	printLayout();
	//player->refreshInfo();
}

// displays room
void GameLayout::setRoom(Room* room) {
	roomFrame.setRoom(room);
	roomFrame.printInside();
}

// printing messages in adequate places
void GameLayout::print(messageType type, string msg)
{
	switch (type)
	{
	case messageType::score:
		statsFrame.addContent(3, "Money: " + msg);
		break;
	case messageType::ammunition:
		statsFrame.addContent(4, "Bullets: " + msg);
		break;
	case messageType::lives:
		statsFrame.addContent(2, "Lives: " + msg);
		break;
	case messageType::info:
		printInfo(msg);
		break;
	case messageType::timer:
		statsFrame.addContent(8, msg);
		break;
	case messageType::info_delay:
		printInfo(msg+" (press any key)");
		_getch();
		printInfo("");
		break;
	
	default:
		break;
	}
}