#include "Frame.h"
#include "Screen.h"
#include <iostream>
#include <string>

using namespace std;

void Frame::printInside() {

}

void Frame::print(int x, int y) {
	this->topLeft.setX(x);
	topLeft.setY(y);
	printFrame();
	printInside();
};


void Frame::printFrame() {


	printHorizontal(topLeft.getX()+1, topLeft.getY(), width-1);
	printHorizontal(topLeft.getX() +1, topLeft.getY() + height, width-1);
	printVertical(topLeft.getX(), topLeft.getY() +1, height-1);
	printVertical(topLeft.getX() + width, topLeft.getY() +1, height-1);
	gotoxy(topLeft.getX(), topLeft.getY());
	cout << top_left;
	gotoxy(topLeft.getX() + width, topLeft.getY());
	cout << top_right;
	gotoxy(topLeft.getX(), topLeft.getY() +height);
	cout << bottom_left;
	gotoxy(topLeft.getX() + width, topLeft.getY() +height);
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

void Frame::cursor(int stepX, int stepY) {
	gotoxy(topLeft.getX() +stepX, topLeft.getY() +stepY);
}

void Frame::printPoint(int x, int y, char sign) {
	cursor(x, y);
	cout << sign;
}
void Frame::clear()
{
	for (int j = 1; j < height - 1; j++) {
		for (int i = 1; i < width - 1; i++) {
			cursor(i, j);
			cout << ' ';
		}
	}
}


void Frame::clearLine(int nrLine)
{
	   cursor(2, nrLine);
		for (int i = 1; i < width - 2; i++) {
			cout << ' ';
		}
}

void Frame::printLine(int nrLine, string text) {
	clearLine(nrLine);
	cursor(2, nrLine);
	cout << text;
}

void Frame::printCenterLine(int nrLine, string text) {
	clearLine(nrLine);
	cursor( (width-text.size())/2, nrLine);
	cout << text;
}

bool Frame::isInside(int x, int y) {
	return  (x > topLeft.getX() && x <= this->topLeft.getX() +this->width) && (y >= topLeft.getY() && y < topLeft.getY() +this->height);
}