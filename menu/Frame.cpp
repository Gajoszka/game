#include "Frame.h"
#include "Screen.h"
#include <iostream>
#include <string>

using namespace std;
Frame::Frame(int width, int height) {
	this->width = width;
	this->height = height;
}
void Frame::printInside() {

}

void Frame::print(int x, int y) {
	this->x = x;
	this->y = y;
	printFrame();
	printInside();
};


void Frame::printFrame() {

	//printPoint(x, y, top_left);
	printHorizontal(x, y, width);
	//printPoint(x + width - 1, y, top_right );
	printVertical(x, y+1, height);
	printHorizontal(x, y + height, width);
	printVertical(x + width, y+1, height);
	gotoxy(1, y + height + 1);
};

void Frame::printVertical(int x, int y, int height) {
	for (int i = 0; i < height; i++) {
		gotoxy(x, y + i);
		cout << wall;
	}
};

void Frame::printHorizontal(int x, int y1, int width) {
	gotoxy(x, y1);
	for (int i = 0; i < width; i++) {
		cout << dash;
	}
};

void Frame::printPoint(int x, int y, char sign) {
	gotoxy(x, y);
	cout << sign;
}
void Frame::printLine(int line, string text) {
	gotoxy(x + 2, y + line + 1);
	cout << text;
}

void Frame::printCenterLine(int line, string text) {
	gotoxy(x + 1+ (width-text.size())/2, y + line + 1);
	cout << text;
}

bool Frame::isInside(int x, int y) {
	return  (x > this->x && x <= this->x+this->width) && (y >= this->y && y < this->y+this->height);
}