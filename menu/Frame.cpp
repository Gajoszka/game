#include "Frame.h"
#include "Screen.h"
#include <iostream>

using namespace std;
Frame::Frame(int width, int height) {
	this->width = width;
	this->height = height;
}

void Frame::printFrame(int x, int y) {
	//printPoint(x, y, top_left);
	printHorizontal(x, y, width);
	//printPoint(x + width - 1, y, top_right );
	printVertical(x, y, height);
	printHorizontal(x, y + height, width);
	printVertical(x + width, y, height);
	gotoxy(1, y + height + 1);
};

void Frame::printVertical(int x, int y, int height) {
	for (int i = 0; i < height; i++) {
		gotoxy(x, y + i);
		cout << '#';
	}
};

void Frame::printHorizontal(int x, int y1, int width) {
	gotoxy(x, y1);
	for (int i = 0; i < width; i++) {
		cout << '-';
	}
};

void Frame::printPoint(int x, int y, char sign) {
	gotoxy(x, y);
	cout << sign;
}