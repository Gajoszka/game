#pragma once
#include <string>
class Frame
{
public:
	Frame(int width, int height);
	void printFrame();
	virtual void printInside();
	virtual bool isInside(int x, int y);
	void print(int x, int y);
	void printPoint(int x, int y, char sign);
private:
	void printVertical(int x,int y,int width);
	void printHorizontal(int x, int y, int height);
	void cursor(int x, int y);
	
	char wall = 186;
	char top_right = 187;
	char top_left = 201;
	char bottom_right = 188;
	char bottom_left = 200;
	char dash = 205;
	//'_';
protected:
	
	void printLine(int line, std::string text);
	void printCenterLine(int line, std::string text);
	int width;
	int height;
	int x;
	int y;
	
};

