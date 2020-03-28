#include "Frame.h"
#include "Screen.h"
#include <iostream>
#include <string>
#include "GameDef.h"
/* Creating frames to divide screen into separate sections and defining insides*/

using namespace std;

void Frame::printInside() {}

// printing frame with its inside data, coordinates from top left corner
void Frame::print(int column, int row) {
	this->topLeft.setColumn(column);
	this->topLeft.setRow(row);
	printFrame();
	printInside();
};

// combining all functions printing particular sides and corners of a frame
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

// printing vertical lines
void Frame::printVertical(int column, int row, int height) {
	for (int i = 0; i < height; i++) {
		gotoxy(column, row + i);
		cout << sign_wall;
	}
};

//printing horizontal lines
void Frame::printHorizontal(int column, int row, int width) {
	gotoxy(column, row);
	for (int i = 0; i < width; i++) {
		cout << sign_dash;
	}
};

// setting cursor to top left corner of chosen column and row
void Frame::moveCursor(int columnStep, int rowStep) {
	gotoxy(topLeft.getColumn() +columnStep, topLeft.getRow() +rowStep);
}

// printing individual characters
 void  Frame::printPoint(int column, int row, char sign) {
	moveCursor(column, row);
	cout << sign;
}

// clearing the inside of a frame
void Frame::clear()
{
	for (int column = 1; column < height - 1; column++) {
		for (int row = 1; row < width - 1; row++) {
			moveCursor(row, column);
			cout << ' ';
		}
	}
}

// clearing chosen line
void Frame::clearLine(int rowNr)
{
	   moveCursor(2, rowNr);
		for (int i = 1; i < width - 2; i++) {
			cout << ' ';
		}
}

// printing text in particular line
void Frame::printLine(int rowNr, string text) {
	clearLine(rowNr);
	moveCursor(2, rowNr);
	cout << text;
}

// printing text so its centered in the frame
void Frame::printCenterLine(int rowNr, string text) {
	clearLine(rowNr);
	moveCursor( (width-(int)text.size())/2, rowNr);
	cout << text;
}

Frame::~Frame()
{
}


// checking whether something is within the frame or not and returning boolean
bool Frame::isInside(int column, int row) {
	return  (column > topLeft.getColumn() && column <= this->topLeft.getColumn() +this->width) && (row >= topLeft.getRow() && row < topLeft.getRow() +this->height);
}
