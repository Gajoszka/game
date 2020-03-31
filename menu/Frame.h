#pragma once
/* Creating frames to divide screen into separate sections and defining insides*/
#include <string>
#include "Point.h"

class Frame
{
public:
	Frame(int width, int height) : topLeft(1, 1) {
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
	void printCenterLine(int rowNr, std::string text);
	void printLine(int rowNr, std::string text);
	~Frame();

private:
	void printVertical(int column, int row, int width);
	void printHorizontal(int column, int row, int height);

protected:
	virtual void moveCursor(int column, int row);
	
	
	int width;
	int height;
	Point topLeft;
};