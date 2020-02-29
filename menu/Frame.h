#pragma once
/* Creating frames and defining its insides*/
#include <string>
#include "Point.h"

// defining frame elements

class Frame
{
public:
	Frame(int width, int height) :topLeft(1, 1) {
		this->width = width;
		this->height = height;
	};
	virtual void printFrame();
	virtual void printInside();
	virtual bool isInside(int column, int row);
	void print(int column, int row);
	void printPoint(int column, int row, char sign);
	void clear();
	void clearLine(int nrLine);
	Point getTopLeft() {
		return topLeft;
	}

private:
	void printVertical(int column, int row, int width);
	void printHorizontal(int column, int row, int height);

protected:
	virtual void moveCursor(int column, int row);
	void printLine(int rowNr, std::string text);
	void printCenterLine(int rowNr, std::string text);
	int width;
	int height;
	Point topLeft;


};

