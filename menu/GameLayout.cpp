#include "GameLayout.h"
#include "Screen.h"
#include <string>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
using namespace std;

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
	////wcscpy_s(cfi.FaceName, L"Lucida Console");
	wcscpy_s(cfi.FaceName, L"Consolas");
	//SetCurrentConsoleFontEx(hStdout, FALSE, &cfi);

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



// displays players username
void GameLayout::printName(string name) {
	statsFrame.printLine(1, "Player: " + name);
}

// displays additional information
void GameLayout::printInfo(string value) {
	infoFrame.printCenterLine(1, value);
}

// displays room
void GameLayout::setRoom(Room* room) {
	roomFrame.setRoom(room);
	roomFrame.printInside();
}

void GameLayout::print(messageType type, string msg)
{
	switch (type)
	{
	case messageType::score:
		statsFrame.printLine(3, "Money: " + msg);
		break;
	case messageType::ammunition:
		statsFrame.printLine(4, "Ammunition: " + ammunition);
		break;
	case messageType::lives:
		statsFrame.printLine(2, "Lives: " + msg);
		break;
	case messageType::info:
		printInfo(msg);
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
