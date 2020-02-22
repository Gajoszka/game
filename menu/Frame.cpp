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


	printHorizontal(x+1, y, width-1);
	printHorizontal(x+1, y + height, width-1);
	printVertical(x, y+1, height-1);
	printVertical(x + width, y+1, height-1);
	gotoxy(x, y);
	cout << top_left;
	gotoxy(x + width, y);
	cout << top_right;
	gotoxy(x, y+height);
	cout << bottom_left;
	gotoxy(x + width, y+height);
	cout << bottom_right;
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

void Frame::cursor(int x, int y) {
	gotoxy(this->x + x, this->y + y);
}

void Frame::printPoint(int x, int y, char sign) {
	cursor(x, y);
	cout << sign;
}
void Frame::printLine(int line, string text) {
	cursor(2, line);
	cout << text;
}

void Frame::printCenterLine(int line, string text) {
	cursor( (width-text.size())/2, line);
	cout << text;
}

bool Frame::isInside(int x, int y) {
	return  (x > this->x && x <= this->x+this->width) && (y >= this->y && y < this->y+this->height);
}