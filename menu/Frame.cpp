#include "Frame.h"
#include "Screen.h"
#include <iostream>
#include <string>

using namespace std;

void Frame::printInside() {

}

void Frame::print(int column, int row) {
	this->topLeft.setColumn(column);
	topLeft.setRow(row);
	printFrame();
	printInside();
};


void Frame::printFrame() {


	printHorizontal(topLeft.getColumn()+1, topLeft.getRow(), width-1);
	printHorizontal(topLeft.getColumn() +1, topLeft.getRow() + height, width-1);
	printVertical(topLeft.getColumn(), topLeft.getRow() +1, height-1);
	printVertical(topLeft.getColumn() + width, topLeft.getRow() +1, height-1);
	gotoxy(topLeft.getColumn(), topLeft.getRow());
	cout << sign_top_left;
	gotoxy(topLeft.getColumn() + width, topLeft.getRow());
	cout << sign_top_right;
	gotoxy(topLeft.getColumn(), topLeft.getRow() +height);
	cout << sign_bottom_left;
	gotoxy(topLeft.getColumn() + width, topLeft.getRow() +height);
	cout << sign_bottom_right;
};

void Frame::printVertical(int column, int row, int height) {
	for (int i = 0; i < height; i++) {
		gotoxy(column, row + i);
		cout << sign_wall;
	}
};

void Frame::printHorizontal(int column, int row, int width) {
	gotoxy(column, row);
	for (int i = 0; i < width; i++) {
		cout << sign_dash;
	}
	
};

void Frame::moveCursor(int columnStep, int rowStep) {
	gotoxy(topLeft.getColumn() +columnStep, topLeft.getRow() +rowStep);
}

void Frame::printPoint(int column, int row, char sign) {
	moveCursor(column, row);
	cout << sign;
}
void Frame::clear()
{
	for (int column = 1; column < height - 1; column++) {
		for (int row = 1; row < width - 1; row++) {
			moveCursor(row, column);
			cout << ' ';
		}
	}
}


void Frame::clearLine(int rowNr)
{
	   moveCursor(2, rowNr);
		for (int i = 1; i < width - 2; i++) {
			cout << ' ';
		}
}

void Frame::printLine(int rowNr, string text) {
	clearLine(rowNr);
	moveCursor(2, rowNr);
	cout << text;
}

void Frame::printCenterLine(int rowNr, string text) {
	clearLine(rowNr);
	moveCursor( (width-text.size())/2, rowNr);
	cout << text;
}

bool Frame::isInside(int column, int row) {
	return  (column > topLeft.getColumn() && column <= this->topLeft.getColumn() +this->width) && (row >= topLeft.getRow() && row < topLeft.getRow() +this->height);
}