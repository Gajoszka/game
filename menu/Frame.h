#pragma once
#include <string>
#include "Point.h"

#define sign_wall  static_cast<char>(186);
#define sign_top_right static_cast<char>(187);
#define sign_top_left static_cast<char>(201);
#define sign_bottom_right static_cast<char>(188);
#define sign_bottom_left static_cast<char>(200);
#define sign_dash static_cast<char>(205);

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
	void printVertical(int column,int row,int width);
	void printHorizontal(int column, int row, int height);

protected:	
	virtual void moveCursor(int column, int row);
	void printLine(int rowNr, std::string text);
	void printCenterLine(int rowNr, std::string text);
	int width;
	int height;
	Point topLeft;
	
	
};

