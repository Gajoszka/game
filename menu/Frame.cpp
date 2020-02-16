#include "Frame.h"
#include "Screen.h"
#include <iostream>

using namespace std;
Frame::Frame(int width, int height) {
	this->width = width;
	this->height = height;
}

void Frame::printFrame(int x, int y) {
	printHorizontal(x, y, width);
	printVertical(x, y, height);
	printHorizontal(x, y + height, width);
	printVertical(x + width, y, height);
};

void Frame::printVertical(int x, int y, int height) {
	
	for (int i = 0; i < height; i++) {
		gotoxy(x, y + i);
		cout << "#";
	}
};

void Frame::printHorizontal(int x, int y1, int width) {
	gotoxy(x, y1);
	for (int i = 0; i < width; i++) {
		cout << "#";
	}
};