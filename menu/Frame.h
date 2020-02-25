#pragma once
#include <string>
#include "Point.h"
class Frame
{
public:
	Frame(int width, int height) :topLeft(0, 0) {
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
	void printVertical(int column,int y,int width);
	void printHorizontal(int column, int y, int height);
	void moveCursor(int columnStep, int rowStep);
	char sign_wall = 186;
	char sign_top_right = 187;
	char sign_top_left = 201;
	char sign_bottom_right = 188;
	char sign_bottom_left = 200;
	char sign_dash = 205;
	//'_';
protected:
	
	void printLine(int rowNr, std::string text);
	void printCenterLine(int rowNr, std::string text);
	int width;
	int height;
	Point topLeft;
	
	
};

